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
#include <QFile>
#include "characters/haro.h"
#include "windows/more_win.h"
#include "windows/dress_win.h"
#include "windows/setwin.h"
#include "characters/rinai.h"
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
    void initButton(bool a,int b);
    void Imageset(QLabel* image,QPixmap pixmap);
    void initLayout();  //初始化布局管理器  这个主要用于加载角色，放在布局管理器中角色会随着窗口的伸缩变换

    //槽函数部分
    void settingClicked();
    void dressClicked();
    void moreClicked();
    void testClicked();

    void btnstatus();//记录按钮显示状态

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
    haro* _haro;
    riNai* _rinai;
    slime* _slime;
//窗口部分
    more_win *More;
    dress_win *Dress;
    setwin *Set;
    int size;//体型大小
    QHBoxLayout* body_part; //用于加载charater的，在initLayout函数中用到

//按钮部分
    QPushButton* btn_exit;
    QPushButton* btn_dress;
    QPushButton* btn_more;
    QPushButton* btn_setting;
    QPushButton* btn_test;

    int btnSwitch1,btnSwitch2;//按钮显示开关

//鼠标拖动部分
    QPoint startPos;//记录起始坐标
    bool isMousePressed;//判断是否点击

};
#endif // CHAMELEON_H
