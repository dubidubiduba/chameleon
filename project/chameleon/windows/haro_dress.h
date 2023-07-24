#ifndef HARO_DRESS_H
#define HARO_DRESS_H

#include <QWidget>
#include <QtGui/QPainter>
#include <vector>
#include <QPixmap>
#include <QPushButton>
#include <QBitmap>
#include <QDebug>
#include <QWheelEvent>
#include <QButtonGroup>

namespace Ui {
class haro_dress;
}
const int NUM = 8;
class haro_dress : public QWidget
{
    Q_OBJECT

public:
    explicit haro_dress(QWidget *parent = nullptr,QWidget* p=nullptr,QWidget* chameleon=nullptr);
    ~haro_dress();

    void initwindow();
    void accept(std::vector<QPixmap> &body, std::vector<QPixmap> &ears,int bodyNum,int earsNum);
    void imageLoad();
    void initBtn();
    void bodyChange();
    void earsChange();
    int win_width=280;
    int win_height=360;
    int labelSize = 130;
private:
    Ui::haro_dress *ui;
    QWidget* m_parent;

    std::vector<QPixmap> body,ears;//各部件对应图片容器
    QPushButton *bodyBtn[NUM],*earsBtn[NUM];//各部件对应按钮容器
    QButtonGroup *bodyBox,*earsBox;//按钮组
    int bodyNum,earsNum;//身体和耳朵对应装扮序号
    int y=0;//鼠标中键滑动轴对应y坐标
    int num=8;//装扮数量
protected:
    void paintEvent(QPaintEvent *event) override;
    void wheelEvent(QWheelEvent *event);
};

#endif // HARO_DRESS_H
