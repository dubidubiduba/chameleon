#include "calendar_win.h"
#include "ui_calendar_win.h"

calendar_win::calendar_win(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::calendar_win)
{
    ui->setupUi(this);
}

calendar_win::~calendar_win()
{
    delete ui;
}
