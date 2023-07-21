/********************************************************************************
** Form generated from reading UI file 'setwin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETWIN_H
#define UI_SETWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setwin
{
public:
    QSlider *sizeSlider;
    QLabel *sizeLabel;

    void setupUi(QWidget *setwin)
    {
        if (setwin->objectName().isEmpty())
            setwin->setObjectName(QString::fromUtf8("setwin"));
        setwin->resize(400, 300);
        sizeSlider = new QSlider(setwin);
        sizeSlider->setObjectName(QString::fromUtf8("sizeSlider"));
        sizeSlider->setGeometry(QRect(70, 140, 241, 20));
        sizeSlider->setMouseTracking(true);
        sizeSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:sizeSlider\n"
"{\n"
"height:20px;\n"
"border:0px:\n"
"left:5px;\n"
"right:5px;\n"
"}\n"
"QSlider::add-page:sizeSlider\n"
"{\n"
"background:#bcbcbc;\n"
"border-radius:4px;\n"
"}\n"
"QSlider::sub-page:sizeSlider\n"
"{\n"
"background:#439cf3;\n"
"border-radius:4px;\n"
"}\n"
""));
        sizeSlider->setMinimum(60);
        sizeSlider->setMaximum(1600);
        sizeSlider->setSingleStep(20);
        sizeSlider->setPageStep(20);
        sizeSlider->setOrientation(Qt::Horizontal);
        sizeLabel = new QLabel(setwin);
        sizeLabel->setObjectName(QString::fromUtf8("sizeLabel"));
        sizeLabel->setGeometry(QRect(170, 70, 69, 31));

        retranslateUi(setwin);

        QMetaObject::connectSlotsByName(setwin);
    } // setupUi

    void retranslateUi(QWidget *setwin)
    {
        setwin->setWindowTitle(QCoreApplication::translate("setwin", "Form", nullptr));
        sizeLabel->setText(QCoreApplication::translate("setwin", "<html><head/><body><p><span style=\" font-size:12pt; color:#1341ad;\">\345\260\272\345\257\270</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setwin: public Ui_setwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETWIN_H
