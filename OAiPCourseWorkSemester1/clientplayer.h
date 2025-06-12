#ifndef CLIENTPLAYER_H
#define CLIENTPLAYER_H

#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTcpSocket>
#include <QResizeEvent>
#include <QTextBrowser>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <qhostaddress.h>
#include "myloginmeniu.h"

namespace Ui {
class ClientPlayer;
}

class ClientPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit ClientPlayer(QWidget *parent = nullptr);
    ~ClientPlayer();

private:
    Ui::ClientPlayer *ui;
    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
    QTextBrowser *chat;
    QLineEdit *lineEditChat;
    QPushButton *enterButton;
    QTcpSocket *socket;
    int portForConnect;
    QHostAddress address;
    quint32 messageSize;
    QString name;
    MyLoginMeniu *meniu;
    QLabel *labelWinner;

    void resizeEvent(QResizeEvent *event) override;
    void showEvent(QShowEvent *event) override;
    void changeEvent(QEvent *event) override;
    void addMyEllipse(QPointF point, QBrush brush);
    void addMyLine(QPointF startPoint, QPointF endPoint, QBrush brush);
    void addMessage(QString str);
    void addMeniu();
    void sendToServerWord(QString str);
    void showingWinner(QString str);

private slots:
    void slotReadyRead();
    void registration();
    void enterButtonClickedSlot();
};

#endif // CLIENTPLAYER_H
