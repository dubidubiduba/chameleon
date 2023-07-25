#include "more_win.h"
#include "ui_more_win.h"

more_win::more_win(QWidget *parent,QWidget* p) :
    QWidget(parent),
    ui(new Ui::more_win)
{
    ui->setupUi(this);
    m_parent = p;
    initWindow();
    initBtn();
    initConnect();
    notepad = new noteWindow(this);
}

more_win::~more_win()
{
    delete ui;
    delete notepad;
}
/*这个窗口包括一些扩展功能的按钮，你可能需要自己去找一些图标
  可能需要注意：窗口大小发生变化时这个窗口不要遮住角色了，在设置这个窗口的位置时可能需要与一个父类窗口产生关联。
*/
void more_win::initWindow()
{
    int win_width = 80;
    int win_height = 220;
    int X = m_parent->geometry().x() - win_width;
    int Y = m_parent->geometry().y()+m_parent->geometry().height()/2-win_height/2;
    this->setGeometry(X,Y,win_width,win_height);
    setWindowOpacity(0.8);//设置透明度
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
}
void more_win::initBtn()
{
    btn_calendar    =new QPushButton(this);
    btn_clock       =new QPushButton(this);
    btn_weather     =new QPushButton(this);
    btn_note     =new QPushButton(this);
    btn_music     =new QPushButton(this);

    setStyleSheet("QPushButton{border:4px solid black;"
                  "background-color:rgb(173, 216, 230);border-radius: 10px;}"
                  "QPushButton::hover{background-color:rgb(180,255,255);}"
                  "QPushButton:pressed{background-color:rgb(60,170,150);}");

    btn_calendar->setIcon(QIcon(":/src/images/icon/calendar.png"));
    btn_clock->setIcon(QIcon(":/src/images/icon/clock.png"));
    btn_weather->setIcon(QIcon(":/src/images/icon/weather.png"));
    btn_note->setIcon(QIcon(":/src/images/icon/note.png"));
    btn_music->setIcon(QIcon(":/src/images/icon/music.png"));


    setButtonsGeo(btn_calendar);
    setButtonsGeo(btn_clock);
    setButtonsGeo(btn_weather);
    setButtonsGeo(btn_note);
    setButtonsGeo(btn_music);
}

void more_win::setButtonsGeo(QPushButton* button)
{
    btnSize = this->geometry().width()/1.5;
    double X = this->frameGeometry().width()/2 -  btnSize/2;
    static int Y = 0;
    QSize temp(btnSize/1.2,btnSize/1.2);
    button->setIconSize(temp);  //
    button->setGeometry(X,Y,btnSize,btnSize);
    Y += btnSize + 2;
}
void more_win::initConnect()
{
    connect(btn_calendar,&QPushButton::clicked,this,&more_win::calendarClicked);
    connect(btn_clock,&QPushButton::clicked,this,&more_win::clockClicked);
    connect(btn_weather,&QPushButton::clicked,this,&more_win::weatherClicked);
    connect(btn_note,&QPushButton::clicked,this,&more_win::notepadClicked);

}

void more_win::moveButtons(int speed,int flag)
{
    int temp = speed*flag;
    double X = this->frameGeometry().width()/2 -  btnSize/2;
    btn_calendar->move(X,btn_calendar->y()+temp);
    btn_clock->move(X,btn_clock->y()+temp);
    btn_weather->move(X,btn_weather->y()+temp);
    btn_note->move(X,btn_note->y()+temp);
    btn_music->move(X,btn_music->y()+temp);
}

/*---------------------------------槽函数部分-----------------------------------*/
/*
    点击对应按钮实现对应的功能，如果需要弹出窗口，窗口类的命名规范参考windows目录下的那三个窗口

*/
void more_win::weatherClicked()
{

}

void more_win::notepadClicked()
{
    if(notepad->isHidden())
    {   notepad->move(x()-notepad->frameGeometry().width(),y()+frameGeometry().height()/2-notepad->frameGeometry().height()/2);
        notepad->show();
    }
    else
    {
        notepad->hide();
    }
}

void more_win::clockClicked()
{

}

void more_win::calendarClicked()
{
}

/*--------------------------------------------------------------------*/
void more_win::wheelEvent(QWheelEvent *event)
{
    static int speed = 40;//滚动速度
    if(event->delta()<0)
    {
        moveButtons(speed,-1);
    }
    else
    {
        moveButtons(speed,1);
    }
    update();
}
