#ifndef MORE_WIN_H
#define MORE_WIN_H

#include <QWidget>
#include <QFormLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QWheelEvent>
#include "noteWindow.h"
#include <QMouseEvent>
#include "calendar_win.h"
#include<QPixmap>
#include <QFileDialog>
#include<QSoundEffect>
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
    void winstatus();
//
    void weatherClicked();
    void notepadClicked();
    void clockClicked();
    void calendarClicked();
    void screenshotClicked();

    void wheelEvent(QWheelEvent *event);
    void moveButtons(int speed,int flag);
public:
noteWindow* notepad;
calendar_win *Calendar;
    int winSwitch=0;

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
    QPushButton* btn_skip;
    QPushButton* btn_communion;
    QPushButton* btn_screensh;
    double btnSize ;
    //“Ù–ß
    QSoundEffect *clicksound;
};

#endif // MORE_WIN_H
