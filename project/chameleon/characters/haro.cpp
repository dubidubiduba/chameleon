#include "haro.h"

haro::haro(QWidget* parent)
{
    m_parent = parent;
    imageLoad();
    eyesMovementLoad();
    initBody();
    qsrand(QTime::currentTime().msec());
    timer1 = new QTimer;
    timer2 = new QTimer;
    interval_time = 10000;
    timer2->start(interval_time);
    connect(timer1,&QTimer::timeout,this,&haro::faceMovement);
    connect(timer2,&QTimer::timeout,this,&haro::moveStart);
}
haro::~haro()
{
    delete bodyImage;
}
void haro::initBody()
{
    bodyImage = new QLabel(m_parent);
    earsImage = new QLabel(m_parent);
    eyesImage = new QLabel(m_parent);
    stripeImage = new QLabel(m_parent);

    Body = new QVBoxLayout(m_parent);
    ears_part = new QVBoxLayout(bodyImage);
    eyes_part = new QVBoxLayout(earsImage);
    stripe_part = new QVBoxLayout(eyesImage);

    Body->addWidget(bodyImage);
    ears_part->addWidget(earsImage);
    eyes_part->addWidget(eyesImage);
    stripe_part->addWidget(stripeImage);

    Imageset(bodyImage ,body[0]);
    Imageset(earsImage,ears1[0]);
    Imageset(eyesImage,eyes);
    Imageset(stripeImage,stripe);
}
void haro::Imageset(QLabel* image,QPixmap pixmap)  //用来给label设置图片,主要用于整个pet的加载
{
    int size = m_parent->frameGeometry().width();
    image->setPixmap(pixmap);
    image->setPixmap(pixmap.scaled(size,size));//使用scaled修改图片大小，能避免图片因缩放模糊
    image->setScaledContents(true);  //使图片完全填充
    image->resize(size,size);
}

void haro::imageLoad()
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

    ears1.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/def_ears1.png")));
    ears1.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/blue_ears1.png")));
    ears1.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/pink_ears1.png")));
    ears1.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/icefire_ears1.png")));
    ears1.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/cat_ears1.png")));
    ears1.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/Gundam_ears1.png")));
    ears1.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/drill_ears1.png")));
    ears1.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/angel_ears1.png")));

    ears2.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/def_ears2.png")));
    ears2.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/blue_ears2.png")));
    ears2.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/pink_ears2.png")));
    ears2.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/icefire_ears2.png")));
    ears2.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/cat_ears2.png")));
    ears2.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/Gundam_ears2.png")));
    ears2.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/drill_ears2.png")));
    ears2.push_back(QPixmap(QString(":/src/images/haro-images/appearance/ears/angel_ears2.png")));

    eyes.load(":/src/images/haro-images/appearance/eyes/def_eyes.png");
    stripe.load(":/src/images/haro-images/appearance/stripe.png");
}

void haro::eyesMovementLoad()  //将每一帧的图片存入QPixmap数组
{
    faceNum.push_back(9);//帧数-例：9代表9帧
    faceNum.push_back(0);//起始位置-例：0代表该表情第一张图片下标
    for(int i = 1; i<=faceNum[0]; i++)//表情0-眨眼
        movement.push_back(QPixmap(QString(":/src/images/haro-images/movement/blink/%1.png").arg(i)));/*insert the value to "%1" */
    faceNum.push_back(12);
    faceNum.push_back(9);
    for(int i = 1; i<=faceNum[2]; i++)//表情1-心动
        movement.push_back(QPixmap(QString(":/src/images/haro-images/movement/heart/%1.png").arg(i)));
    faceNum.push_back(16);
    faceNum.push_back(21);
    for(int i = 1; i<=faceNum[4]; i++)//表情2-疑惑
        movement.push_back(QPixmap(QString(":/src/images/haro-images/movement/question/%1.png").arg(i)));
    faceNum.push_back(15);
    faceNum.push_back(37);
    for(int i = 1; i<=faceNum[6]; i++)//表情3-闭眼
        movement.push_back(QPixmap(QString(":/src/images/haro-images/movement/closeEyes/%1.png").arg(i)));
    faceNum.push_back(9);
    faceNum.push_back(52);
    for(int i = 1; i<=faceNum[8]; i++)//表情4-单眨眼
        movement.push_back(QPixmap(QString(":/src/images/haro-images/movement/wink/%1.png").arg(i)));

    face = -1;//表情序号初始化为-1，不生效
    faceSum = 5;//表情数量
}
void haro::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        qDebug() << "clicked";
        face = random()%faceSum;
        face_index = faceNum[face*2];
        face_cnt = faceNum[face*2+1];
        //m_index = 0;
        //timer->start(250);
    }

}
void haro::moveStart()
{
    face = qrand()%faceSum;
    face_index = faceNum[face*2+1];
    face_cnt = faceNum[face*2];
    timer1->start(250);
}
void haro::faceMovement()
{
    static int idx=0;
    if(idx == face_cnt)
    {
        Imageset(eyesImage,eyes);
        idx=0;
        interval_time = 10000 + qrand()%5000;
        timer2->start(interval_time);          //
        timer1->stop();
    }
    Imageset(eyesImage,movement[face_index+idx]);
    idx++;
}

