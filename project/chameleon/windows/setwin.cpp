#include "setwin.h"
#include "ui_setwin.h"

setwin::setwin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setwin)
{
    ui->setupUi(this);

    QBitmap bmp(this->size());//设置圆角边框
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),50,50);
    setMask(bmp);
    setWindowOpacity(0.95);//设置透明度
    setStyleSheet("background-color:white;");

    Qt::WindowFlags m_flags = windowFlags();//保持窗口置顶1
    setWindowFlags(m_flags|Qt::WindowStaysOnTopHint);//保持窗口置顶2


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
    haroSize = value;
    sizeNum->setNum(haroSize);
}


