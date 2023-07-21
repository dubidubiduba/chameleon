#include "rinai.h"

riNai::riNai(QWidget *parent)
{
    m_parent = parent;
    body = new QLabel(m_parent);
    bodyLoad();
    initBody();
    initDress();
}

riNai::~riNai()
{
    delete timer;
}
void riNai::bodyLoad()
{
    for(int i=1 ; i<=5 ; i++)
    {
        Bodys.push_back(QPixmap(QString(":/src/images/riNai-images/body/body%1.png").arg(i)));
    }
}
/*void riNai::initBody()
{
    body = new QLabel(m_parent);
    timer = new QTimer;
    timer->start(300);
    connect(timer,&QTimer::timeout,this,&riNai::movement);
}*/
void riNai::initBody()  //gpt写的，产生了奇妙的化学反应
{
    body = new QLabel(m_parent);
    timer = new QTimer;
    timer->start(250);
    connect(timer, &QTimer::timeout, this, &riNai::movement);

    int imageSize = qMax(body->width(), body->height()); // 获取图片大小限制为窗口的最小边长
    body->setMinimumSize(imageSize, imageSize); // 设置窗口的最小尺寸

}

void riNai::movement()
{
    static int index=0;
    Imageset(body,Bodys[index]);
    index = (++index)%5;
}
#define B
#ifdef A
void riNai::Imageset(QLabel* image,QPixmap pixmap)  //用来给label设置图片,主要用于整个pet的加载
{
    int size = m_parent->frameGeometry().width();
    //qDebug() <<"before "<<m_parent->frameGeometry().width();
    image->setPixmap(pixmap);
    image->setPixmap(pixmap.scaled(size,size));//使用scaled修改图片大小，能避免图片因缩放模糊
    image->setScaledContents(true);  //使图片完全填充
    //qDebug() <<"after "<<m_parent->frameGeometry().width();
    //image->resize(size,size);
    //image->move(m_parent->frameGeometry().width()/2 - size/2,  //居中显示
    //m_parent->frameGeometry().height()/2 - size/2);
}
#else
void riNai::Imageset(QLabel* image, QPixmap pixmap)  //可能存在无法缩小窗口的问题
{
    int imageSize = qMax(image->width(), image->height()); // 获取图片大小限制为窗口的最小边长
    QPixmap scaledPixmap = pixmap.scaled(imageSize, imageSize, Qt::KeepAspectRatio); // 按比例缩放图片
    image->setPixmap(scaledPixmap);
    image->setScaledContents(true);
}
#endif
void riNai::initDress()
{

}
