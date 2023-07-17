#ifndef HARO_H
#define HARO_H

#include <QWidget>
#include <QLabel>
class haro
{
public:
    haro(QWidget* parent = nullptr);
    ~haro();
    void initBody();  //初始化身体
    void Imageset(QLabel* image,QPixmap pixmap); //给QLabel设置背景图片

    QLabel* body;
private:

    QWidget* m_parent;
};

#endif // HARO_H
