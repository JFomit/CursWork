#ifndef WRITEPUZZLE_H
#define WRITEPUZZLE_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QResizeEvent>

namespace Ui {
class WritePuzzle;
}

class WritePuzzle : public QDialog
{
    Q_OBJECT

public:
    explicit WritePuzzle(QWidget *parent = nullptr);
    ~WritePuzzle();

    QString getPazzleWord();

signals:
    void puzzleIsReady();

private:
    Ui::WritePuzzle *ui;
    QString pazzleWord;
    QLabel *labelText;
    QLineEdit *lineEditWriteWord;
    QPushButton *buttonEnter;

    void resizeEvent(QResizeEvent *event) override;

private slots:
    void buttonEnterClickedSlot();

};

#endif // WRITEPUZZLE_H
