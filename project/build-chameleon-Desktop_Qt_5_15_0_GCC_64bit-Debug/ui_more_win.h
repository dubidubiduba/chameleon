/********************************************************************************
** Form generated from reading UI file 'more_win.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORE_WIN_H
#define UI_MORE_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_more_win
{
public:

    void setupUi(QWidget *more_win)
    {
        if (more_win->objectName().isEmpty())
            more_win->setObjectName(QString::fromUtf8("more_win"));
        more_win->resize(400, 300);

        retranslateUi(more_win);

        QMetaObject::connectSlotsByName(more_win);
    } // setupUi

    void retranslateUi(QWidget *more_win)
    {
        more_win->setWindowTitle(QCoreApplication::translate("more_win", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class more_win: public Ui_more_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORE_WIN_H
