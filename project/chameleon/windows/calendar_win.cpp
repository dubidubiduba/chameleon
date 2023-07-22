#include "calendar_win.h"
#include "ui_calendar_win.h"

calendar_win::calendar_win(QWidget *parent,QWidget* p) :
    QWidget(parent),
    ui(new Ui::calendar_win)
{
    ui->setupUi(this);
    c_parent=p;
    initWindow();

}

calendar_win::~calendar_win()
{
    delete ui;
}
void calendar_win::initWindow()
{
    int win_width = 400;
    int win_height = 300;
    int X = c_parent->geometry().x()- win_width ;//
    int Y = c_parent->geometry().y()+c_parent->geometry().height()/2-win_height/2;
    this->setGeometry(X,Y,win_width,win_height);
    this->setWindowTitle("日历");
    //setWindowOpacity(0.8);//设置透明度
    //setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
}
