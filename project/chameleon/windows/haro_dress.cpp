#include "haro_dress.h"
#include "ui_haro_dress.h"
#include "chameleon.h"

haro_dress::haro_dress(QWidget *parent,QWidget* p,QWidget* chameleon) :
    QWidget(parent),
    ui(new Ui::haro_dress)
{
    ui->setupUi(this);
    m_parent = chameleon;

    initwindow();
    imageLoad();
    initBtn();

}

haro_dress::~haro_dress()
{
    delete ui;
}

void haro_dress::initwindow()
{
    QBitmap bmp(this->size());//设置圆角边框
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),50,50);
    setMask(bmp);
    setWindowOpacity(0.9);//设置透明度
    setStyleSheet("background-color:white;");

    Qt::WindowFlags m_flags = windowFlags();//保持窗口置顶1
    setWindowFlags(m_flags|Qt::WindowStaysOnTopHint);//保持窗口置顶2

    int X = m_parent->geometry().x() - win_width-10;
    int Y = m_parent->geometry().y()+m_parent->geometry().height()/2-win_height/2;
    this->setGeometry(X,Y,win_width,win_height);

    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
}

void haro_dress::imageLoad()
{
    //载入装扮图片 将图片存入QPixmap数组body里
    body.push_back(QPixmap(QString(":/src/images/haro-images/appearance/body/def_body.png")));
    body.push_back(QPixmap(QString(":/src/images/haro-images/appearance/body/blue_body.png")));
    body.push_back(QPixmap(QString(":/src/images/haro-images/appearance/body/pink_body.png")));
    body.push_back(QPixmap(QString(":/src/images/haro-images/appearance/body/icefire_body.png")));
    body.push_back(QPixmap(QString(":/src/images/haro-images/appearance/body/cat_body.png")));
    body.push_back(QPixmap(QString(":/src/images/haro-images/appearance/body/Gundam_body.png")));
    body.push_back(QPixmap(QString(":/src/images/haro-images/appearance/body/drill_body.png")));
    body.push_back(QPixmap(QString(":/src/images/haro-images/appearance/body/angel_body.png")));

    ears.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/def_ears1.png")));
    ears.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/blue_ears1.png")));
    ears.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/pink_ears1.png")));
    ears.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/icefire_ears1.png")));
    ears.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/cat_ears1.png")));
    ears.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/Gundam_ears1.png")));
    ears.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/drill_ears1.png")));
    ears.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/angel_ears1.png")));
}

void haro_dress::wheelEvent(QWheelEvent *event)
{
    static int speed = 20;//滚动速度

    if(event->delta() > 0){
        if(y<0)
            y += speed;
    }
    else{
        if(y>-115*num+115)
            y -= speed;
    }

    for(int i=0;i<num;i++){
        bodyBtn[i]->move(43,y+i*120+105);
        earsBtn[i]->move(167,y+i*120+105);
    }

    update();//调用绘画事件函数-paintEvent来更新画面
}

void haro_dress::paintEvent(QPaintEvent *)
{
    static QPixmap dummy(":/src/images/haro-images/appearance/body/dummy.png");
    QPainter painter(this);
    //painter.drawPixmap(0,0,120,120,body[0]);
    for(int i = 0;i<num;i++)
        painter.drawPixmap(0,y+i*120,120,120,body[i]);
    for(int i = 0;i<num;i++){
        painter.drawPixmap(130,y+i*120,120,120,dummy);
        painter.drawPixmap(130,y+i*120,120,120,ears[i]);
    }
}

void haro_dress::initBtn()
{

    setStyleSheet("QPushButton{border:none;"
                  "background-color:rgb(200,200,200)"
                  ";border-radius: 15px;"
                  "border-style:outset;}"
                  "QPushButton::hover{background-color:rgb(170,200,255);}"
                  "QPushButton:checked{background-color:rgb(100,120,230);}");

    bodyBox =  new QButtonGroup;
    earsBox =  new QButtonGroup;
    bodyBox->setExclusive(true);
    earsBox->setExclusive(true);

    for(int i=0;i<num;i++){
        bodyBtn[i] = new QPushButton(this);
        bodyBtn[i]->setFixedSize(40,20);
        bodyBtn[i]->move(43,y+i*120+105);
        bodyBtn[i]->setIcon(QIcon(":/src/images/icon/choose.png"));
        bodyBtn[i]->setCheckable(1);
        bodyBox->addButton(bodyBtn[i],i);

        earsBtn[i] = new QPushButton(this);
        earsBtn[i]->setFixedSize(40,20);
        earsBtn[i]->move(167,y+i*120+105);
        earsBtn[i]->setIcon(QIcon(":/src/images/icon/choose.png"));
        earsBtn[i]->setCheckable(1);
        earsBox->addButton(earsBtn[i],i);
    }

    //当信号存在重载函数时，需要使用函数指针进行强制类型转换
    connect(bodyBox,
            static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),
            this,&haro_dress::bodyChange);
    connect(earsBox,
            static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),
            this,&haro_dress::earsChange);
}
void haro_dress::bodyChange()
{
    chameleon* CML = qobject_cast<chameleon*>(m_parent);
    int idx=0;
    if(bodyBtn[0]->isChecked()) idx = 0;
    else if(bodyBtn[1]->isChecked()) idx = 1;
    else if(bodyBtn[2]->isChecked()) idx = 2;
    else if(bodyBtn[3]->isChecked()) idx = 3;
    else if(bodyBtn[4]->isChecked()) idx = 4;
    else if(bodyBtn[5]->isChecked()) idx = 5;
    else if(bodyBtn[6]->isChecked()) idx = 6;
    else if(bodyBtn[7]->isChecked()) idx = 7;

    CML->_haro->Imageset(CML->_haro->bodyImage,body[idx]);

}

void haro_dress::earsChange()
{
    chameleon* CML = qobject_cast<chameleon*>(m_parent);
    int idx=0;
    if(earsBtn[0]->isChecked()) idx = 0;
    else if(earsBtn[1]->isChecked()) idx = 1;
    else if(earsBtn[2]->isChecked()) idx = 2;
    else if(earsBtn[3]->isChecked()) idx = 3;
    else if(earsBtn[4]->isChecked()) idx = 4;
    else if(earsBtn[5]->isChecked()) idx = 5;
    else if(earsBtn[6]->isChecked()) idx = 6;
    else if(earsBtn[7]->isChecked()) idx = 7;

    CML->_haro->Imageset(CML->_haro->earsImage,ears[idx]);
}
