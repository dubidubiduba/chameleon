#include "haro.h"

haro::haro(QWidget* parent)
{
    m_parent = parent;
    body = new QLabel(m_parent);
}
haro::~haro()
{
    delete body;
}
void haro::initBody()
{
    body = new QLabel(m_parent);
    Imageset(body,QPixmap(QString(":/images/appearance/body/blue_body.png")));
}
void haro::Imageset(QLabel* image,QPixmap pixmap)  //用来给label设置图片,主要用于整个pet的加载
{
    int size = m_parent->frameGeometry().width();
    image->setPixmap(pixmap);
    image->setPixmap(pixmap.scaled(size,size));//使用scaled修改图片大小，能避免图片因缩放模糊
    image->setScaledContents(true);  //使图片完全填充
    image->resize(size,size);
    //image->move(m_parent->frameGeometry().width()/2 - size/2,  //居中显示
                //m_parent->frameGeometry().height()/2 - size/2);
}
