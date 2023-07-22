#ifndef MORE_WIN_H
#define MORE_WIN_H

#include <QWidget>
#include <QFormLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QWheelEvent>
#include<QPixmap>
#include <QFileDialog>
namespace Ui {
class more_win;
}

class more_win : public QWidget
{
    Q_OBJECT

public:
    more_win(QWidget *parent = nullptr,QWidget* p=nullptr);
    ~more_win();
    void initBtn();
    void initWindow();
    void initConnect();
    void setButtonsGeo(QPushButton* button);
//
    void weatherClicked();
    void notepadClicked();
    void clockClicked();
    void calendarClicked();
    void screenshotClicked();

    void wheelEvent(QWheelEvent *event);
    void moveButtons(int speed,int flag);



private:
    Ui::more_win *ui;
    QWidget* m_parent;
//

    QPushButton* btn_weather;
    QPushButton* btn_calendar;
    QPushButton* btn_clock;
    QPushButton* btn_note;
    QPushButton* btn_translation;
    QPushButton* btn_music;
    QPushButton* btn_screen;
    QPushButton* btn_skip;
    QPushButton* btn_communion;
    QPushButton* btn_screensh;
    double btnSize ;
};

#endif // MORE_WIN_H
