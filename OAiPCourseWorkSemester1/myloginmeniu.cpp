#include "myloginmeniu.h"
#include "ui_myloginmeniu.h"
#include "mylayout.h"
#include <qhostaddress.h>
#include <qobject.h>

MyLoginMeniu::MyLoginMeniu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyLoginMeniu)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("background-color: #FFE6F2;");

    labelName = new QLabel("Введите ваш ник",this);
    labelName->setAlignment(Qt::AlignCenter);
    labelName->setStyleSheet("font-size: 24px; color: #555555; font-weight: bold;");
    labelName->setMinimumHeight(40);
    labelName->setMinimumWidth(220);
    labelName->move(100, 10);

    lineEditName = new QLineEdit(this);
    lineEditName->setMinimumHeight(40);
    lineEditName->setMinimumWidth(220);
    lineEditName->move(100, 50);

    labelPort = new QLabel ("Код подключения", this);
    labelPort->setAlignment(Qt::AlignCenter);
    labelPort->setStyleSheet("font-size: 24px; color: #555555; font-weight: bold;");
    labelPort->setMinimumHeight(40);
    labelPort->setMinimumWidth(220);
    labelPort->move(100, 90);

    lineEditPort = new QLineEdit(this);
    lineEditPort->setMinimumHeight(40);
    lineEditPort->setMinimumWidth(220);
    lineEditPort->move(100, 130);

    connectButton = new QPushButton(this);
    connectButton->setText("Подключиться");
    connectButton->setMinimumHeight(40);
    connectButton->setMinimumWidth(220);
    connectButton->move(100, 190);

    connect(connectButton, &QPushButton::clicked, this, &MyLoginMeniu::connectButtonClickedSlot);
}

MyLoginMeniu::~MyLoginMeniu()
{
    delete ui;
}

void MyLoginMeniu::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);
    MyLayout::Layout_40_220(labelName, event->size(), QPointF(100, 10));
    MyLayout::Layout_40_220(lineEditName, event->size(), QPoint(100, 50));
    MyLayout::Layout_40_220(labelPort, event->size(), QPoint(100, 90));
    MyLayout::Layout_40_220(lineEditPort, event->size(), QPoint(100, 130));
    MyLayout::Layout_40_220(connectButton, event->size(), QPoint(100, 190));

}

QString MyLoginMeniu::getName() {
    return name;
}

int MyLoginMeniu::getPort() {
    return port;
}

void MyLoginMeniu::connectButtonClickedSlot() {
    if(lineEditName->text().size() == 0) {
        return;
    }

    name = lineEditName->text();
    QString address_port = lineEditPort->text().trimmed();
    QStringList parts = address_port.split(':');
    if (parts.count() != 2) {
        return;
    }

    if (!hostAddress.setAddress(parts[0])) {
        return;
    }
    if(parts[1].toInt() < 1000 || parts[1].toInt() > 65535) {
        return;
    }
    port = parts[1].toInt();
    
    emit successfulRegistration();
}

QHostAddress MyLoginMeniu::getIpAddress() {
    return hostAddress;
}
