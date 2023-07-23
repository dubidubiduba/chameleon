#ifndef DRESS_WIN_H
#define DRESS_WIN_H

#include <QWidget>
#include <QLabel>
#include <QtGui/QPainter>
#include <QPushButton>
#include <QButtonGroup>
namespace Ui {
class dress_win;
}

class dress_win : public QWidget
{
    Q_OBJECT

public:
    explicit dress_win(QWidget *parent=nullptr,QWidget* p=nullptr);
    ~dress_win();

    void close();
    void initWindow();
    void initImages();
    void setImage(QLabel* label,QPixmap pixmap);
    void chooseCharacter();


private:
    Ui::dress_win *ui;
    int win_width = 300;
    int win_height = 400;
    int character_size = 140;
    QWidget *m_parent;

    QLabel *_haro,*_rinai;

    QPushButton *btn_haro,*btn_rinai;
    QButtonGroup *ButtonBox;


protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // DRESS_WIN_H
