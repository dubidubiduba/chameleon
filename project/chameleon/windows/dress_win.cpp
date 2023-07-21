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

/*
   这个类用于弹出一个更换角色的窗口，在这个窗口中提供多种角色，点击相应的角色可以实例化一个character目录中对应角色，将对应角色加载到chameleon主窗口中，同时可能需要将上一个显示的角色对象删除
  可以选择将角色的图片作为按钮的图标，可以参考haro，这里用按钮组完成也许比较合适，暂时只有一个角色，但也许可以多搞一些空按钮？ 遇到问题请联系puck
*/

