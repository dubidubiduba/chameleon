#include "noteWindow.h"
#include "ui_noteWindow.h"

noteWindow::noteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::noteWindow)
{
    ui->setupUi(this);
}

noteWindow::~noteWindow()
{
    delete ui;
}
