/********************************************************************************
** Form generated from reading UI file 'mainplayer.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPLAYER_H
#define UI_MAINPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_MainPlayer
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QDialog *MainPlayer)
    {
        if (MainPlayer->objectName().isEmpty())
            MainPlayer->setObjectName("MainPlayer");
        MainPlayer->resize(800, 600);
        gridLayout = new QGridLayout(MainPlayer);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(MainPlayer);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(MainPlayer);

        QMetaObject::connectSlotsByName(MainPlayer);
    } // setupUi

    void retranslateUi(QDialog *MainPlayer)
    {
        MainPlayer->setWindowTitle(QCoreApplication::translate("MainPlayer", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainPlayer: public Ui_MainPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPLAYER_H
