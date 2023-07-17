#include "slime.h"

slime::slime(QWidget* parent)   //这里接受一个父指针，主要用于和chameleon窗口关联
{
    m_parent = parent;
    body = new QLabel(m_parent);
    initBody();
    initDress();
}
/*写角色的人需要好好读一下haro动态实现的代码，这里可能会产生很多问题，多与puck交流*/
void slime::initBody()
{
    body = new QLabel(m_parent);
    Imageset(body,QPixmap(QString(":/slime-image/body1.png")));
}

void slime::Imageset(QLabel* image,QPixmap pixmap)  //用来给label设置图片,主要用于整个pet的加载
{
    int size = m_parent->frameGeometry().width();
    image->setPixmap(pixmap);
    image->setPixmap(pixmap.scaled(size,size));//使用scaled修改图片大小，能避免图片因缩放模糊
    image->setScaledContents(true);  //使图片完全填充
    image->resize(size,size);
    //image->move(m_parent->frameGeometry().width()/2 - size/2,  //居中显示
    //m_parent->frameGeometry().height()/2 - size/2);
}
void slime::initDress()
{

}
