#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QBrush>

class MyServer : public QTcpServer
{
public:
    MyServer(int port);

    QTcpSocket *socket;

private:
    int port;
    quint32 messageSize;
    QVector<QTcpSocket*> Sockets;
    void SendToClientPointEllipse(QPointF point, QBrush brush);
    void SendToClientPointLine(QPointF startPoint, QPointF endPoint, QBrush brush);
    void SendToClientString(QString str);
    void SendToClientWinner(QString str);

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();

};

#endif // MYSERVER_H
