#ifndef HARO_H
#define HARO_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <vector>
#include <QStackedLayout>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QDebug>
#include <QtCore/QTime>


class haro : public QWidget
{
    Q_OBJECT
public:
    haro(QWidget* parent = nullptr);
    ~haro();
    void initBody();  //初始化身体
    void Imageset(QLabel* image,QPixmap pixmap); //给QLabel设置背景图片
    void imageLoad();
    void eyesMovementLoad();
    void eyesMovement();
    void faceMovement();
    void moveStart();

    void mousePressEvent(QMouseEvent *event);

    QVBoxLayout* Body;

    static int m_index;  //

private:


    QWidget* m_parent;
    QLabel *bodyImage ,*earsImage,*eyesImage,*stripeImage;//各部件对应标签
    QVBoxLayout* ears_part;
    QVBoxLayout* eyes_part;
    QVBoxLayout* stripe_part;

    std::vector<QPixmap> body,ears1,ears2;//各部件对应图片容器

    std::vector<QPixmap> movement;//表情图片容器

    std::vector<QPixmap> spMovement;//特殊动作图片容器

    std::vector<int>faceNum;//每个表情对应帧数与起始位置

    QPixmap eyes,stripe;//眼睛和眼部遮罩

    QTimer *timer1,*timer2;//定时器
    int interval_time; //

    int face; //表情序号
    int faceSum;  //表情数量

    int face_index;
    int face_cnt;


};

#endif // HARO_H
