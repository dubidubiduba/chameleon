#include "dress_win.h"
#include "ui_dress_win.h"

dress_win::dress_win(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dress_win)
{
    ui->setupUi(this);
}

dress_win::~dress_win()
{
    delete ui;
}
/*这个类用于弹出一个更换角色的窗口，在这个窗口中提供多种角色，点击相应的角色可以调用character目录中对应角色的成员函数initBody（），将对应角色加载到chameleon主窗口中，同时可能需要将上一个显示的角色对象删除
*/
