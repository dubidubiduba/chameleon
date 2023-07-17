#include "more_win.h"
#include "ui_more_win.h"

more_win::more_win(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::more_win)
{
    ui->setupUi(this);
}

more_win::~more_win()
{
    delete ui;
}
/*这个窗口包括一些扩展功能的按钮，你可能需要自己去找一些图标
  可能需要注意：窗口大小发生变化时这个窗口不要遮住角色了，在设置这个窗口的位置时可能需要与一个父类窗口产生关联。
*/
