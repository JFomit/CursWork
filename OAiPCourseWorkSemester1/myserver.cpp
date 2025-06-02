#include "myserver.h"
#include <QDebug>
#include <QPixmap>

MyServer::MyServer(int port) : port(port), messageSize(0){
    if(this->listen(QHostAddress::Any, port)) {
        qDebug() << "start";
    } else {
        qDebug() << " no start";
    }
}

void MyServer::incomingConnection(qintptr socketDescriptor) {
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &MyServer::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
    qDebug() << "client connected";
}

void MyServer::slotReadyRead()
{
    QTcpSocket *clientSocket = (QTcpSocket*)sender();
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_6_2);

    while (true) {

        qDebug() << clientSocket->bytesAvailable();

        if (clientSocket->bytesAvailable() < (int)sizeof(quint32)) {
            break;
        }

        if (messageSize == 0) {
            in >> messageSize;
        }

        if (clientSocket->bytesAvailable() < messageSize) {
            break;
        }

        quint8 messageType = 0;
        in >> messageType;

        if (in.status() == QDataStream::Ok) {
            switch (messageType) {
            case 1: {
                QPointF point;
                QBrush brush;
                in >> point >> brush;
                SendToClientPointEllipse(point, brush);
                qDebug() << "отправили ellipse";
                break;
            }
            case 2: {
                QPointF startPoint, endPoint;
                QBrush brush;
                in >> startPoint >> endPoint >> brush;
                SendToClientPointLine(startPoint, endPoint, brush);
                qDebug() << "отправлиси line";
                break;
            }
            case 3: {
                QString str;
                in >> str;
                SendToClientString(str);
                break;
            }
            case 4: {
                QString str;
                in >> str;
                SendToClientWinner(str);

                break;
            }
            default:
                break;
            }
            messageSize = 0;
        }
    }
}

void MyServer::SendToClientPointEllipse(QPointF point, QBrush brush) {
    QByteArray Data;
    Data.clear();

    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);

    out << quint32(0)
        << quint8(1)
        << point
        << brush;

    quint32 realSize = Data.size() - sizeof(quint32);

    out.device()->seek(0);
    out << realSize;

    for(int i = 1; i < Sockets.size(); i++) {
        Sockets[i]->write(Data);
    }
}

void MyServer::SendToClientPointLine(QPointF startPoint, QPointF endPoint, QBrush brush) {
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

    for(int i = 1; i < Sockets.size(); i++) {
        Sockets[i]->write(Data);
    }

}

void MyServer::SendToClientString(QString str) {
    QByteArray Data;
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);

    quint32 messageSize = sizeof(quint8) + str.size();

    out << messageSize
        << quint8(3)
        << str;

    for(int i =  0; i < Sockets.size(); i++) {
        Sockets[i]->write(Data);
    }
}

void MyServer::SendToClientWinner(QString str) {
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

    for(int i = 1; i < Sockets.size(); i++) {
        Sockets[i]->write(Data);
    }
}

