#include "clientplayer.h"
#include "ui_clientplayer.h"
#include "mylayout.h"

ClientPlayer::ClientPlayer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ClientPlayer)
    ,messageSize(0)
{
    ui->setupUi(this);

    ui->label->setStyleSheet("background-color: #FFE6F2;");

    graphicsView = new QGraphicsView(this);
    graphicsView->move(20, 60);
    graphicsView->setMinimumWidth(450);
    graphicsView->setMinimumHeight(450);

    scene = new QGraphicsScene(this);
    graphicsView->setScene(scene);
    scene->setSceneRect(20,60,450, 450);
    graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    chat = new QTextBrowser(this);
    chat->setMinimumHeight(410);
    chat->setMinimumWidth(250);
    chat->move(510, 60);

    lineEditChat = new QLineEdit(this);
    lineEditChat->setMinimumHeight(30);
    lineEditChat->setMinimumWidth(200);
    lineEditChat->move(510, 480);

    enterButton = new QPushButton(this);
    enterButton->setMinimumHeight(30);
    enterButton->setMinimumWidth(45);
    enterButton->setMaximumHeight(30);
    enterButton->setMaximumWidth(45);
    enterButton->move(715, 480);
    enterButton->setText("->");

    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::readyRead, this, &ClientPlayer::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    connect(enterButton, &QPushButton::clicked, this, &ClientPlayer::enterButtonClickedSlot);

    addMeniu();

}

ClientPlayer::~ClientPlayer()
{
    delete ui;
}

void ClientPlayer::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);
    graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

    MyLayout::Layout_450_450(graphicsView, event->size(), QPointF(20, 60));
    MyLayout::Layout_410_250(chat, event->size(), QPointF(510, 60));
    MyLayout::Layout_30_200(lineEditChat, event->size(), QPointF(510, 480));
    MyLayout::Layout_30_45(enterButton, event->size(), QPointF(715, 480));

}

void ClientPlayer::showEvent(QShowEvent *event) {
    QDialog::showEvent(event);
    graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

void ClientPlayer::changeEvent(QEvent *event) {
    QDialog::changeEvent(event);
    if(event->type() == QEvent::WindowStateChange) {
        graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }
}

void ClientPlayer::slotReadyRead() {

    QTcpSocket *clientSocket = (QTcpSocket*)sender();
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_6_2);

    while (true) {
        if (clientSocket->bytesAvailable() < (int)sizeof(quint32)) {
            break;
        }

        if (messageSize == 0) {
            in >> messageSize;
        }

        if (clientSocket->bytesAvailable() < messageSize) {
            break;
        }

        quint8 messageType;
        in >> messageType;

        if (in.status() == QDataStream::Ok) {
            switch (messageType) {
            case 1: {
                QPointF point;
                QBrush brush;
                in >> point >> brush;

                addMyEllipse(point, brush);
                // qDebug() << "рисуем круг";
                break;
            }
            case 2: {
                QPointF startPoint, endPoint;
                QBrush brush;
                in >> startPoint >> endPoint >> brush;

                addMyLine(startPoint, endPoint, brush);
                // qDebug() << "рисуем линию";
                break;
            }
            case 3: {
                QString str;
                in >> str;

                addMessage(str);
                break;
            }
            case 4: {
                QString str;
                in >> str;
                showingWinner(str);
            }
            default:
                break;
            }
            messageSize = 0;
        }
    }
}

void ClientPlayer::addMyEllipse(QPointF point, QBrush brush) {

    scene->addEllipse(point.x() - 5,
                      point.y() - 5,
                      10,
                      10,
                      QPen(Qt::NoPen),
                      brush);
}

void ClientPlayer::addMyLine(QPointF startPoint, QPointF endPoint, QBrush brush) {
    scene->addLine(startPoint.x(),
                   startPoint.y(),
                   endPoint.x(),
                   endPoint.y(),
                   QPen(brush, 10, Qt::SolidLine, Qt::RoundCap));
}

void ClientPlayer::addMeniu() {
    meniu = new MyLoginMeniu();
    connect(meniu, &MyLoginMeniu::successfulRegistration, this, &ClientPlayer::registration);
    meniu->exec();
}

void ClientPlayer::registration() {
    name = meniu->getName();
    portForConnect = meniu->getPort();
    socket->connectToHost("127.0.0.1", portForConnect);
    delete meniu;
}

void ClientPlayer::sendToServerWord(QString str) {
    QByteArray Data;
    Data.clear();

    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);

    QString result = name + ": " + str;

    quint32 messageSize = sizeof(quint8) + result.size();

    out << messageSize
        <<quint8(3)
        <<result;

    socket->write(Data);
}

void ClientPlayer::enterButtonClickedSlot() {
    sendToServerWord(lineEditChat->text());
    lineEditChat->clear();
}

void ClientPlayer::addMessage(QString str) {
    chat->append(str);
}

void ClientPlayer::showingWinner(QString str) {
    graphicsView->setVisible(false);
    chat->setVisible(false);
    lineEditChat->setVisible(false);
    enterButton->setVisible(false);
    labelWinner = new QLabel(this);
    labelWinner->setAlignment(Qt::AlignCenter);
    labelWinner->setText("Победу одержал игрок: " + str);
    labelWinner->setStyleSheet("font-size: 32px; color: #555555; font-weight: bold;");
    labelWinner->setMinimumHeight(100);
    labelWinner->setMinimumWidth(600);
    labelWinner->move(100,250);
    labelWinner->show();
}








