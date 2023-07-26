#include "note_win.h"
#include "ui_note_win.h"
note_win::note_win(QWidget *parent, QWidget* p) :
    QWidget(parent),
    ui(new Ui::note_win)
{
    ui->setupUi(this);
    n_parent = p;
    initWindow();
}

note_win::~note_win()
{
    delete ui;
}

void note_win::initWindow()
{
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);//去掉窗口标题
    int win_width = 400;
    int win_height = 300;
    int X = n_parent->geometry().x()- win_width ;//
    int Y = n_parent->geometry().y()+ n_parent->geometry().height()/2-win_height/2;
    this->setGeometry(X,Y,win_width,win_height);
    this->setWindowTitle("记事本");

}
