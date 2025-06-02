/********************************************************************************
** Form generated from reading UI file 'writepuzzle.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRITEPUZZLE_H
#define UI_WRITEPUZZLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WritePuzzle
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QDialog *WritePuzzle)
    {
        if (WritePuzzle->objectName().isEmpty())
            WritePuzzle->setObjectName("WritePuzzle");
        WritePuzzle->resize(400, 300);
        gridLayout = new QGridLayout(WritePuzzle);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(WritePuzzle);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(WritePuzzle);

        QMetaObject::connectSlotsByName(WritePuzzle);
    } // setupUi

    void retranslateUi(QDialog *WritePuzzle)
    {
        WritePuzzle->setWindowTitle(QCoreApplication::translate("WritePuzzle", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WritePuzzle: public Ui_WritePuzzle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRITEPUZZLE_H
