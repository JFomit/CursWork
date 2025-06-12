/********************************************************************************
** Form generated from reading UI file 'clientplayer.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTPLAYER_H
#define UI_CLIENTPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ClientPlayer
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QDialog *ClientPlayer)
    {
        if (ClientPlayer->objectName().isEmpty())
            ClientPlayer->setObjectName("ClientPlayer");
        ClientPlayer->resize(800, 600);
        gridLayout = new QGridLayout(ClientPlayer);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(ClientPlayer);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(ClientPlayer);

        QMetaObject::connectSlotsByName(ClientPlayer);
    } // setupUi

    void retranslateUi(QDialog *ClientPlayer)
    {
        ClientPlayer->setWindowTitle(QCoreApplication::translate("ClientPlayer", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ClientPlayer: public Ui_ClientPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTPLAYER_H
