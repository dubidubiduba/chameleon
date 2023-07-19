/********************************************************************************
** Form generated from reading UI file 'chameleon.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAMELEON_H
#define UI_CHAMELEON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chameleon
{
public:

    void setupUi(QWidget *chameleon)
    {
        if (chameleon->objectName().isEmpty())
            chameleon->setObjectName(QString::fromUtf8("chameleon"));
        chameleon->resize(800, 600);

        retranslateUi(chameleon);

        QMetaObject::connectSlotsByName(chameleon);
    } // setupUi

    void retranslateUi(QWidget *chameleon)
    {
        chameleon->setWindowTitle(QCoreApplication::translate("chameleon", "chameleon", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chameleon: public Ui_chameleon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAMELEON_H
