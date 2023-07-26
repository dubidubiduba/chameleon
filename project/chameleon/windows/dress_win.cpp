#include "dress_win.h"
#include "ui_dress_win.h"
#include "chameleon.h"

dress_win::dress_win(QWidget *parent,QWidget* p) :
    QWidget(parent),
    ui(new Ui::dress_win)
{
    ui->setupUi(this);
    m_parent = p;
    Dress = new haro_dress(nullptr,this,p);
    initWindow();
    initImages();
}

dress_win::~dress_win()
{
    delete ui;
}

void dress_win::initWindow()
{
    int X = m_parent->geometry().x() - win_width;
    int Y = m_parent->geometry().y()+m_parent->geometry().height()/2-win_height/2;
    this->setGeometry(X,Y,win_width,win_height);
    setWindowOpacity(0.9);//设置透明度
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
}

void dress_win::initImages()
{
    _haro = new QLabel(this);
    _rinai= new QLabel(this);
    _lxh = new QLabel(this);
    _ncs = new QLabel(this);

    setImage(_haro,QPixmap(QString(":/src/images/characters/haro.png")));
    _haro->move(5,5);

    setImage(_rinai,QPixmap(QString(":/src/images/characters/rinai.png")));
    _rinai->move(145,5);

    setImage(_lxh,QPixmap(QString(":/src/images/characters/lxh.png")));
    _lxh->move(5,200);

    setImage(_ncs,QPixmap(QString(":/src/images/characters/ncs.png")));
    _ncs->move(145,200);
    /*-------------------------------------------------------------------------*/
    setStyleSheet("QPushButton{border:none;"
                  "background-color:rgb(200,200,200)"
                  ";border-radius: 15px;"
                  "border-style:outset;}"
                  "QPushButton::hover{background-color:rgb(170,200,255);}"
                  "QPushButton:checked{background-color:rgb(100,120,230);}");
    btn_haro = new QPushButton(this);
    btn_rinai = new QPushButton(this);
    btn_lxh = new QPushButton(this);
    btn_ncs = new QPushButton(this);

    btn_haro->setIcon(QIcon(":/src/images/icon/choose.png"));
    btn_rinai->setIcon(QIcon(":/src/images/icon/choose.png"));
    btn_lxh->setIcon(QIcon(":/src/images/icon/choose.png"));
    btn_ncs->setIcon(QIcon(":/src/images/icon/choose.png"));

    btn_haro->resize(character_size,character_size/4);
    btn_rinai->resize(character_size,character_size/4);
    btn_lxh->resize(character_size,character_size/4);
    btn_ncs->resize(character_size,character_size/4);

    btn_haro->move(5,_haro->y()+character_size);
    btn_rinai->move(145,_rinai->y()+character_size);
    btn_lxh->move(5,_lxh->y()+character_size);
    btn_ncs->move(145,_ncs->y()+character_size);

    btn_haro->setCheckable(true);
    btn_rinai->setCheckable(true);
    btn_lxh->setCheckable(true);
    btn_ncs->setCheckable(true);

    ButtonBox = new QButtonGroup(this);
    ButtonBox->setExclusive(true);
    ButtonBox->addButton(btn_haro);
    ButtonBox->addButton(btn_rinai);
    ButtonBox->addButton(btn_lxh);
    ButtonBox->addButton(btn_ncs);

    connect(ButtonBox, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonClicked), this, &dress_win::chooseCharacter);
}
void dress_win::setImage(QLabel* image,QPixmap pixmap)
{
    image->setPixmap(pixmap);
    image->setPixmap(pixmap.scaled(character_size,character_size));//使用scaled修改图片大小，能避免图片因缩放模糊
    image->setScaledContents(true);  //使图片完全填充
    image->resize(character_size,character_size);
}

void dress_win::chooseCharacter()
{
    chameleon* CML = qobject_cast<chameleon*>(m_parent);
    CML->clearCharacters();
    if(!btn_haro->isChecked()) Dress->hide();
    if(btn_haro->isChecked())
    {
        CML->body_part->addWidget(CML->_haro->bodyImage);
        CML->_haro->bodyImage->show();
        Dress->setGeometry(x()-Dress->win_width-10,y()+height()/2-Dress->win_height/2,Dress->win_width,Dress->win_height);
        Dress->show();
    }
    else if(btn_rinai->isChecked())
    {
        CML->body_part->addWidget(CML->_rinai->body);
        CML->_rinai->body->show();
    }
    else if(btn_lxh->isChecked())
    {
        CML->body_part->addWidget(CML->_lxh->body);
        CML->_lxh->body->show();
    }
    else if(btn_ncs->isChecked())
    {
        CML->body_part->addWidget(CML->_ncs->body);
        CML->_ncs->body->show();
    }

}



void dress_win::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawRoundedRect(rect(), 10, 10);
}

/*
   这个类用于弹出一个更换角色的窗口，在这个窗口中提供多种角色，点击相应的角色可以实例化一个character目录中对应角色，将对应角色加载到chameleon主窗口中，同时可能需要将上一个显示的角色对象删除
  可以选择将角色的图片作为按钮的图标，可以参考haro，这里用按钮组完成也许比较合适，暂时只有一个角色，但也许可以多搞一些空按钮？ 遇到问题请联系puck
*/

