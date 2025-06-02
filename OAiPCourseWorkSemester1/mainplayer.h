#ifndef MAINPLAYER_H
#define MAINPLAYER_H

#include <QDialog>
#include <QGraphicsView>
#include <QResizeEvent>
#include <QTcpSocket>
#include <QPushButton>
#include <QLabel>
#include <QTextBrowser>
#include "myserver.h"
#include "paintscene.h"
#include "writepuzzle.h"

namespace Ui {
class MainPlayer;
}

class MainPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit MainPlayer(QWidget *parent = nullptr);
    ~MainPlayer();

private slots:
    void ellipsePointSlot();
    void linePointSlot();

    void slotReadyRead();

    void redButtonClickedSlot();
    void greenButtonClickedSlot();
    void yellowButtonClickedSlot();
    void blueButtonClickedSlot();
    void eraserButtonClickedSlot();
    void registrationWord();


private:
    Ui::MainPlayer *ui;
    QGraphicsView *graphicsViev;
    PaintScene *scene;
    QTcpSocket *socket;
    int myPort;
    MyServer *server;
    QLabel *labelShowPort;
    QPushButton *redButton;
    QPushButton *greenButton;
    QPushButton *yellowButton;
    QPushButton *blueButton;
    QPushButton *eraserButton;
    QBrush brush;
    QTextBrowser *chat;
    quint32 messageSize;
    WritePuzzle *writePuzzle;
    QString puzzleWord;
    QLabel *labelWinner;

    void resizeEvent(QResizeEvent *event) override;
    void showEvent(QShowEvent *event) override;
    void changeEvent(QEvent *event) override;
    void sendToServerPointEllipse(QPointF point);
    void sendToServerPointLine(QPointF startPoint, QPointF endPoint);
    void sendToServerWinner(QString str);
    void addMessage(QString str);
    int generatePortCode();
    void addMeniu();
    bool searchWinner(QString str);
    QString searchNameWinner(QString str);
    QString searchWord(QString word);
    void showingWinner(QString str);

    void addButton(QPushButton *&button, QPointF point, QSize size, QColor color);

};

#endif // MAINPLAYER_H
