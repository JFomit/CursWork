/********************************************************************************
** Form generated from reading UI file 'myloginmeniu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLOGINMENIU_H
#define UI_MYLOGINMENIU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_MyLoginMeniu
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QDialog *MyLoginMeniu)
    {
        if (MyLoginMeniu->objectName().isEmpty())
            MyLoginMeniu->setObjectName("MyLoginMeniu");
        MyLoginMeniu->resize(400, 300);
        gridLayout = new QGridLayout(MyLoginMeniu);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(MyLoginMeniu);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(MyLoginMeniu);

        QMetaObject::connectSlotsByName(MyLoginMeniu);
    } // setupUi

    void retranslateUi(QDialog *MyLoginMeniu)
    {
        MyLoginMeniu->setWindowTitle(QCoreApplication::translate("MyLoginMeniu", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyLoginMeniu: public Ui_MyLoginMeniu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLOGINMENIU_H
