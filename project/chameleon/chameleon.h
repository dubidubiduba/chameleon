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
#include<QSound>
#include <QSoundEffect>
#include <QMediaPlayer>
#include "characters/haro.h"
#include "windows/more_win.h"
#include "windows/dress_win.h"
#include"windows/set_win.h"
#include "characters/rinai.h"
#include "characters/lxh.h"
#include "characters/ncs.h"
#include "QHBoxLayout"


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
    void reinitButton();
    //槽函数部分
    void settingClicked();
    void dressClicked();
    void moreClicked();
    void testClicked();

    void btnstatus();//记录按钮显示状态
    void winstatus();
    void initCharacters();
    void clearCharacters();  //切换角色时调用，清除角色

    //character部分
    haro* _haro;
    riNai* _rinai;
    LXH* _lxh;
    NCS* _ncs;

    QVBoxLayout* body_part;
protected://重载三个鼠标事件的函数
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;


private:
    Ui::chameleon *ui;
    int win_width=380;    //主窗口的宽  434
    int win_height=380;   //主窗口的高  387
    int ScreenWidth;  //显示器屏幕的宽度
    int ScreenHeight;   //显示器屏幕的高度


//窗口部分
    more_win *More;
    dress_win *Dress;
    setwin *Set;
    int size;//体型大小


//按钮部分
    QPushButton* btn_exit;
    QPushButton* btn_dress;
    QPushButton* btn_more;
    QPushButton* btn_setting;

//音效
    QSoundEffect  *clicksound;

    int btnSwitch1,btnSwitch2;//按钮显示开关
    int winSwitch;

//鼠标拖动部分
    QPoint startPos;//记录起始坐标
    bool isMousePressed;//判断是否点击

};
#endif // CHAMELEON_H
