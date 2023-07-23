#include "calendar_win.h"
#include "ui_calendar_win.h"

calendar_win::calendar_win(QWidget *parent,QWidget* p) :
    QWidget(parent),
    ui(new Ui::calendar_win)
{
    ui->setupUi(this);
    c_parent=p;
    initWindow();
    //ui->label->setStyleSheet("font-size: 18px;");
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
    //ui->label->setStyleSheet ("QLabel {background-color:green;color:cyan;}");
    //ui->label->setStyleSheet ("font-size: 50px;font-family: 黑体;background-color:argb(60, 60, 60, 130); rgb(255, 255, 255);");
    ui->label->setStyleSheet("color:green;");
    connect(ui->calendarWidget, SIGNAL(selectionChanged()), this, SLOT(DateChange()));



}

calendar_win::~calendar_win()
{
    delete ui;
}
void calendar_win::initWindow()
{
    int win_width = 400;
    int win_height = 350;
    int X = c_parent->geometry().x()- win_width ;//
    int Y = c_parent->geometry().y()+c_parent->geometry().height()/2-win_height/2;
    this->setGeometry(X,Y,win_width,win_height);
    this->setWindowTitle("日历");
    ui->calendarWidget->setWindowFlags(Qt::FramelessWindowHint);
    ui->calendarWidget->setStyleSheet(
        "QCalendarWidget {"
        "background-color: #F5DEB3;"
        "}"
        "QCalendarWidget QAbstractItemView {"
        "selection-background-color: #FF8C00;"
        "selection-color: white;"
        "font-size: 18px;"
        "font-family: 黑体"
        "}"
        "QCalendarWidget QToolBar {"
        "selection-background-color: #F5DEB3;"
        "font-family: 黑体"
        "}"
        );

    ui->calendarWidget->setGridVisible(true);//将网格显示出来
    setAttribute(Qt::WA_TranslucentBackground);//设置背景透明
    Qt::WindowFlags m_flags = windowFlags();
    setWindowFlags(m_flags|Qt::WindowStaysOnTopHint);
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
    //setWindowOpacity(0.8);//设置透明度
    //setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
}
void calendar_win::DateChange()
{
    ui->label->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
}
