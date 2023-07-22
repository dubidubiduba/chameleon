#include "set_win.h"
#include "ui_set_win.h"
#include"chameleon.h"

setwin::setwin(QWidget *parent,QWidget *p) :
    QWidget(parent),
    ui(new Ui::setwin)
{
    ui->setupUi(this);

    QBitmap bmp(this->size());//设置圆角边框
    bmp.fill();
    QPainter d(&bmp);
    d.setPen(Qt::NoPen);
    d.setBrush(Qt::black);
    d.drawRoundedRect(bmp.rect(),50,50);
    setMask(bmp);
    setWindowOpacity(0.95);//设置透明度
    setStyleSheet("background-color:white;");
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);//去掉窗口标题
    Qt::WindowFlags m_flags = windowFlags();//保持窗口置顶1
    setWindowFlags(m_flags|Qt::WindowStaysOnTopHint);//保持窗口置顶2

    m_parent=p;
}

setwin::~setwin()
{
    delete ui;
}

void setwin::setSize(int size)
{
    haroSize = size;

    QFont ft;
    ft.setPointSize(12);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::blue);
    sizeNum = new QLabel(this);
    sizeNum->move(120,100);
    sizeNum->resize(120,20);
    sizeNum->setFont(ft);
    sizeNum->setPalette(pa);
    sizeNum->setNum(haroSize);
    sizeNum->show();

    ui->sizeSlider->setValue(haroSize);
}

int setwin::getSize()
{
    return haroSize;
}

void setwin::on_sizeSlider_valueChanged(int value)
{
    int temp=haroSize;
    haroSize = value;
    sizeNum->setNum(haroSize);
    if(value<=170)
        return;
    m_parent->resize(haroSize*1.4,haroSize*1.4);
    QRect windowGeometry=m_parent->geometry();
    int sizew=m_parent->width();   //窗口的宽度
    int sizeh=m_parent->height();    // 窗口的高度

    int windowX = windowGeometry.x(); // 获取窗口的横坐标
    int windowY = windowGeometry.y(); // 获取窗口的纵坐标
    chameleon* parentWindow = qobject_cast<chameleon*>(m_parent);

    if(haroSize>temp)
    {
        m_parent->move(windowX-value/150,windowY-value/150);
        //获取父窗口的指针，并调用其成员函数
        parentWindow->reinitButton();
    }
    else
    {
        m_parent->move(windowX+value/150,windowY+value/150);//140
        parentWindow->reinitButton();
    }
}



