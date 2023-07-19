/********************************************************************************
** Form generated from reading UI file 'dress_win.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRESS_WIN_H
#define UI_DRESS_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dress_win
{
public:

    void setupUi(QWidget *dress_win)
    {
        if (dress_win->objectName().isEmpty())
            dress_win->setObjectName(QString::fromUtf8("dress_win"));
        dress_win->resize(400, 300);

        retranslateUi(dress_win);

        QMetaObject::connectSlotsByName(dress_win);
    } // setupUi

    void retranslateUi(QWidget *dress_win)
    {
        dress_win->setWindowTitle(QCoreApplication::translate("dress_win", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dress_win: public Ui_dress_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRESS_WIN_H
