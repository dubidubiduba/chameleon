#include "more_win.h"
#include "ui_more_win.h"

more_win::more_win(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::more_win)
{
    ui->setupUi(this);
    initBtn();
}

more_win::~more_win()
{
    delete ui;
}
/*这个窗口包括一些扩展功能的按钮，你可能需要自己去找一些图标
  可能需要注意：窗口大小发生变化时这个窗口不要遮住角色了，在设置这个窗口的位置时可能需要与一个父类窗口产生关联。
*/
void more_win::initBtn()
{
    btn_calendar    =new QPushButton(this);
    btn_clock       =new QPushButton(this);
    btn_weather     =new QPushButton(this);
    btn_note     =new QPushButton(this);
    btn_screen     =new QPushButton(this);
    btn_skip     =new QPushButton(this);
    btn_communion    =new QPushButton(this);
    btn_translation     =new QPushButton(this);
    btn_music     =new QPushButton(this);
    btn_calendar->setGeometry(0,0,32,32);
    btn_clock->setGeometry(0,40,32,32);
    btn_weather->setGeometry(0,80,32,32);
    btn_note->setGeometry(0,120,32,32);
    btn_screen->setGeometry(0,160,32,32);
    btn_skip->setGeometry(0,200,32,32);
    btn_communion->setGeometry(40,0,32,32);
    btn_translation->setGeometry(40,40,32,32);
    btn_music->setGeometry(40,80,32,32);
    btn_calendar->setIcon(QIcon(":/src/images/icon/calendar.png"));
    btn_clock->setIcon(QIcon(":/src/images/icon/clock.png"));
    btn_weather->setIcon(QIcon(":/src/images/icon/weather.png"));
    btn_note->setIcon(QIcon(":/src/images/icon/note.png"));
    btn_screen->setIcon(QIcon(":/src/images/icon/screen.jpg"));
    btn_skip->setIcon(QIcon(":/src/images/icon/skip.jpg"));
    btn_communion->setIcon(QIcon(":/src/images/icon/communion.jpg"));
    btn_translation->setIcon(QIcon(":/src/images/icon/translation.jpg"));
    btn_music->setIcon(QIcon(":/src/images/icon/music.png"));
}

void more_win::initConnect()
{
    connect(btn_weather,&QPushButton::clicked,this,&more_win::weatherClicked);
    connect(btn_note,&QPushButton::clicked,this,&more_win::notepadClicked);
    connect(btn_clock,&QPushButton::clicked,this,&more_win::clockClicked);
    connect(btn_calendar,&QPushButton::clicked,this,&more_win::calendarClicked);
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

}

void more_win::clockClicked()
{

}

void more_win::calendarClicked()
{
}
