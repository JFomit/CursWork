#include "mainplayer.h"
#include "ui_mainplayer.h"
#include "mylayout.h"
#include "writepuzzle.h"
#include <qhostaddress.h>
#include <QNetworkInterface>
#include <qnetworkinterface.h>

QHostAddress getHostAddress() {
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost) {
            return address;
        }
    }

    return QHostAddress::LocalHost;
}

MainPlayer::MainPlayer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainPlayer), server(nullptr)
    ,brush(Qt::red), messageSize(0)
{
    ui->setupUi(this);

    ui->label->setStyleSheet("background-color: #FFE6F2;");
    graphicsViev = new QGraphicsView(this);
    graphicsViev->move(20, 60);
    graphicsViev->setMinimumWidth(450);
    graphicsViev->setMinimumHeight(450);

    scene = new PaintScene(this);
    graphicsViev->setScene(scene);
    scene->setSceneRect(20,60,450, 450);
    graphicsViev->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    graphicsViev->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    graphicsViev->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    graphicsViev->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsViev->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(scene, &PaintScene::ellipsePointSignals, this, &MainPlayer::ellipsePointSlot);
    connect(scene, &PaintScene::linePointSignal, this, &MainPlayer::linePointSlot);

    myPort = generatePortCode();
    server = new MyServer(myPort);

    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", myPort);

    labelShowPort = new QLabel(this);
    labelShowPort->setText(QString("Код для подключения: %1:%2").arg(getHostAddress().toString()).arg(myPort));
    labelShowPort->setStyleSheet("font-size: 24px; color: #555555; font-weight: bold;");
    labelShowPort->move(20, 10);
    labelShowPort->setMinimumHeight(40);
    labelShowPort->setMinimumWidth(350);

    chat = new QTextBrowser(this);
    chat->setMinimumHeight(450);
    chat->setMinimumWidth(250);
    chat->move(510, 60);

    addButton(redButton, QPointF(20, 525), QSize(90, 40), QColor(Qt::red));
    addButton(greenButton, QPointF(110, 525), QSize(90, 40), QColor(Qt::green));
    addButton(yellowButton, QPointF(200, 525), QSize(90, 40), QColor(Qt::yellow));
    addButton(blueButton, QPointF(290, 525), QSize(90, 40), QColor(Qt::blue));
    addButton(eraserButton, QPointF(380, 525), QSize(90, 40), QColor(Qt::white));

    addMeniu();

}

MainPlayer::~MainPlayer()
{
    delete ui;
    if(server != nullptr) {
        delete server;
    }
}

void MainPlayer::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);
    graphicsViev->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

    MyLayout::Layout_450_450(graphicsViev, event->size(), QPointF(20, 60));

    MyLayout::Layout_40_90(redButton, event->size(), QPointF(20, 525));
    MyLayout::Layout_40_90(greenButton, event->size(), QPointF(110, 525));
    MyLayout::Layout_40_90(yellowButton, event->size(), QPointF(200, 525));
    MyLayout::Layout_40_90(blueButton, event->size(), QPointF(290, 525));
    MyLayout::Layout_40_90(eraserButton, event->size(), QPointF(380, 525));
    MyLayout::Layout_40_350(labelShowPort, event->size(), QPointF(20, 10));
    MyLayout::Layout_450_250(chat, event->size(), QPointF(510, 60));

    connect(socket, &QTcpSocket::readyRead, this, &MainPlayer::slotReadyRead);

    connect(redButton, &QPushButton::clicked, this, &MainPlayer::redButtonClickedSlot);
    connect(greenButton, &QPushButton::clicked, this, &MainPlayer::greenButtonClickedSlot);
    connect(yellowButton, &QPushButton::clicked, this, &MainPlayer::yellowButtonClickedSlot);
    connect(blueButton, &QPushButton::clicked, this, &MainPlayer::blueButtonClickedSlot);
    connect(eraserButton, &QPushButton::clicked, this, &MainPlayer::eraserButtonClickedSlot);

}

void MainPlayer::showEvent(QShowEvent *event) {
    QDialog::showEvent(event);
    graphicsViev->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

void MainPlayer::changeEvent(QEvent *event) {
    QDialog::changeEvent(event);
    if(event->type() == QEvent::WindowStateChange) {
        graphicsViev->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }
}

void MainPlayer::slotReadyRead(){
    QTcpSocket *clientSocket = (QTcpSocket*)sender();
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_6_2);

    if(clientSocket->bytesAvailable() < (int)sizeof(quint32)) {
        return;
    }

    if(messageSize == 0) {
        in >> messageSize;
    }

    if(clientSocket->bytesAvailable() < messageSize) {
        return;
    }

    quint8 messageType;
    in >> messageType;

    if(in.status() == QDataStream::Ok) {
        if(messageType == 3) {
            QString str;
            in >> str;

            addMessage(str);

            if(searchWinner(str)) {
                sendToServerWinner(searchNameWinner(str));
                showingWinner(searchNameWinner(str));
            }
            messageSize = 0;
        }
    }
}

void MainPlayer::addMessage(QString str) {
    chat->append(str);
}

void MainPlayer::ellipsePointSlot() {
    QPointF point = scene->getEndPoint();
    sendToServerPointEllipse(point);
}

void MainPlayer::linePointSlot() {
    QPointF startPoint = scene->getStartPoint();
    QPointF endPoint = scene->getEndPoint();
    sendToServerPointLine(startPoint, endPoint);
}

void MainPlayer::sendToServerPointLine(QPointF startPoint, QPointF endPoint) {
    QByteArray Data;
    Data.clear();

    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);

    out << quint32(0)
        << quint8(2)
        << startPoint
        << endPoint
        << brush;

    quint32 realSize = Data.size() - sizeof(quint32);

    out.device()->seek(0);
    out << realSize;

    socket->write(Data);
}

void MainPlayer::sendToServerPointEllipse(QPointF point) {
    QByteArray Data;
    Data.clear();

    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);

    out << quint32(0)
        <<quint8(1)
        <<point
        <<brush;

    quint32 realSize = Data.size() - sizeof(quint32);

    out.device()->seek(0);
    out << realSize;

    socket->write(Data);
}

void MainPlayer::sendToServerWinner(QString str) {
    QByteArray Data;
    Data.clear();

    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);

    out << quint32(0)
        <<quint8(4)
        << str;

    quint32 realSize = Data.size() - sizeof(quint32);

    out.device()->seek(0);
    out << realSize;

    socket->write(Data);

}

int MainPlayer::generatePortCode() {
    std::srand((unsigned int)(std::time(0)));

    int result = 0;

    while(true) {
        result = std::rand() % 65535;
        if(result >= 1000 && result <= 65535) {
            return result;
        }
    }
}

void MainPlayer::addButton(QPushButton *&button, QPointF point, QSize size, QColor color) {
    button = new QPushButton(this);
    button->move(point.x(), point.y());
    button->setMinimumHeight(size.height());
    button->setMinimumWidth(size.width());
    button->setStyleSheet(QString("background-color: %1").arg(color.name()));
}

void MainPlayer::redButtonClickedSlot() {
    brush = QBrush(Qt::red);
    scene->setBrush(brush);
}

void MainPlayer::greenButtonClickedSlot() {
    brush = QBrush(Qt::green);
    scene->setBrush(brush);
}

void MainPlayer::yellowButtonClickedSlot() {
    brush = QBrush(Qt::yellow);
    scene->setBrush(brush);
}

void MainPlayer::blueButtonClickedSlot() {
    brush = QBrush(Qt::blue);
    scene->setBrush(brush);
}

void MainPlayer::eraserButtonClickedSlot() {
    brush = QBrush(Qt::white);
    scene->setBrush(brush);
}

void MainPlayer::addMeniu() {
    writePuzzle = new WritePuzzle();
    connect(writePuzzle, &WritePuzzle::puzzleIsReady, this, &MainPlayer::registrationWord);
    writePuzzle->exec();
}

void MainPlayer::registrationWord() {
    puzzleWord = writePuzzle->getPazzleWord();
    delete writePuzzle;
}

QString MainPlayer::searchWord(QString word) {
    int index = word.indexOf(':');
    return word.mid(index + 2);
}

bool MainPlayer::searchWinner(QString str) {
    QString word = searchWord(str);

    if(word == puzzleWord) {
        return true;
    }
    return false;
}

QString MainPlayer::searchNameWinner(QString str) {
    int index = str.indexOf(':');
    return str.left(index);
}

void MainPlayer::showingWinner(QString str) {
    graphicsViev->setVisible(false);
    labelShowPort->setVisible(false);
    chat->setVisible(false);
    redButton->setVisible(false);
    yellowButton->setVisible(false);
    blueButton->setVisible(false);
    greenButton->setVisible(false);
    eraserButton->setVisible(false);

    labelWinner = new QLabel(this);
    labelWinner->setAlignment(Qt::AlignCenter);
    labelWinner->setText("Победу одержал игрок: " + str);
    labelWinner->setStyleSheet("font-size: 32px; color: #555555; font-weight: bold;");
    labelWinner->setMinimumHeight(100);
    labelWinner->setMinimumWidth(600);
    labelWinner->move(100,250);
    labelWinner->show();
}
