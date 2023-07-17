#ifndef SLIME_H
#define SLIME_H
#include <QLabel>
#include <QWidget>

class slime
{
public:
    slime(QWidget* parent);
    void initBody();  
    void Imageset(QLabel* image,QPixmap pixmap); //给QLabel设置背景图片
    void initDress();  //弹出一个换装的窗口

    QLabel* body;
private:
    QWidget* m_parent;
    QWidget* Dress_win;
};

#endif // SLIME_H
