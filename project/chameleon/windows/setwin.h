#ifndef SETWIN_H
#define SETWIN_H

#include "windows/more_win.h"
#include <QWidget>
#include <QBitmap>
#include <QPainter>
#include <QLabel>
#include <QString>
#include<QSlider>
namespace Ui {
class setwin;
}

class setwin : public QWidget
{
    Q_OBJECT

public:
    explicit setwin(QWidget *parent=nullptr,QWidget *p=nullptr);
    ~setwin();

    void setSize(int);//设置size值

    int getSize();//外部获取size值

private slots:


    void on_sizeSlider_valueChanged(int value);//滑动条槽函数

private:

    int haroSize;//haro大小参数

    QLabel *sizeNum;//显示size值标签
    QWidget* m_parent;
    Ui::setwin *ui;
};

#endif // SETWIN_H
