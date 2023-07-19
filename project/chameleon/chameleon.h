#ifndef CHAMELEON_H
#define CHAMELEON_H

#include <QWidget>
#include <QScreen>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QButtonGroup>
#include <QMouseEvent>
#include "characters/haro.h"
#include "windows/more_win.h"
#include "windows/dress_win.h"
#include "characters/slime.h"
QT_BEGIN_NAMESPACE
namespace Ui { class chameleon; }
QT_END_NAMESPACE

class chameleon : public QWidget
{
    Q_OBJECT

public:
    chameleon(QWidget *parent = nullptr);
    ~chameleon();
    void initWindow(); 
    void initButton();
    void Imageset(QLabel* image,QPixmap pixmap);

    void initLayout();  //初始化布局管理器  这个主要用于加载角色，放在布局管理器中角色会随着窗口的伸缩变换

    //槽函数部分
    void settingClicked();
    void dressClicked();
    void moreClicked();
    void testClicked();

    //
protected://重载三个鼠标事件的函数
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;


private:
    Ui::chameleon *ui;
    int win_width=434;    //主窗口的宽
    int win_height=387;   //主窗口的高
    int ScreenWidth;  //显示器屏幕的宽度
    int ScreenHeight;   //显示器屏幕的高度
//character部分
    slime* S;
    haro* H;
//窗口部分
    more_win *More;
    dress_win *Dress;

    QHBoxLayout* body_part; //用于加载charater的，在initLayout函数中用到

//按钮部分
    QPushButton* btn_exit;
    QPushButton* btn_dress;
    QPushButton* btn_more;
    QPushButton* btn_setting;
    QPushButton* btn_test;

//鼠标拖动部分
    QPoint startPos;//记录起始坐标
    bool isMousePressed;//判断是否点击

};
#endif // CHAMELEON_H
