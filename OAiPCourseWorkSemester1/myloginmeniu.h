#ifndef MYLOGINMENIU_H
#define MYLOGINMENIU_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QResizeEvent>

namespace Ui {
class MyLoginMeniu;
}

class MyLoginMeniu : public QDialog
{
    Q_OBJECT

public:
    explicit MyLoginMeniu(QWidget *parent = nullptr);
    ~MyLoginMeniu();

    QString getName();
    int getPort();

signals:
    void successfulRegistration();

private slots:
    void connectButtonClickedSlot();

private:
    QString name;
    int port;
    Ui::MyLoginMeniu *ui;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QPushButton *connectButton;


    void resizeEvent(QResizeEvent *event) override;

};

#endif // MYLOGINMENIU_H
