#include "writepuzzle.h"
#include "ui_writepuzzle.h"
#include "mylayout.h"

WritePuzzle::WritePuzzle(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WritePuzzle)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("background-color: #FFE6F2;");

    labelText = new QLabel("Загадайте слово", this);
    labelText->setAlignment(Qt::AlignCenter);
    labelText->setStyleSheet("font-size: 24px; color: #555555; font-weight: bold;");
    labelText->setMinimumHeight(40);
    labelText->setMinimumWidth(220);
    labelText->move(90, 60);

    lineEditWriteWord = new QLineEdit(this);
    lineEditWriteWord->setMinimumHeight(40);
    lineEditWriteWord->setMinimumWidth(220);
    lineEditWriteWord->move(90, 110);

    buttonEnter = new QPushButton(this);
    buttonEnter->setText("Подтвердить");
    buttonEnter->setMinimumHeight(40);
    buttonEnter->setMinimumWidth(220);
    buttonEnter->move(90, 160);

    connect(buttonEnter, &QPushButton::clicked, this, &WritePuzzle::buttonEnterClickedSlot);

}

WritePuzzle::~WritePuzzle()
{
    delete ui;
}

void WritePuzzle::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);

    MyLayout::Layout_40_220(labelText, event->size(), QPointF(90, 60));
    MyLayout::Layout_40_220(lineEditWriteWord, event->size(), QPointF(90, 110));
    MyLayout::Layout_40_220(buttonEnter, event->size(), QPointF(90, 160));
}

void WritePuzzle::buttonEnterClickedSlot() {
    if(lineEditWriteWord->text().size() != 0) {
        pazzleWord = lineEditWriteWord->text();
        lineEditWriteWord->clear();
        emit puzzleIsReady();
    }
}

QString WritePuzzle::getPazzleWord() {
    return pazzleWord;
}
