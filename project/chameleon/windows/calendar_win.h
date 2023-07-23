#ifndef CALENDAR_WIN_H
#define CALENDAR_WIN_H

#include <QWidget>

namespace Ui {
class calendar_win;
}

class calendar_win : public QWidget
{
    Q_OBJECT

public:
    explicit calendar_win(QWidget *parent = nullptr,QWidget* p=nullptr);
    void initWindow();
    ~calendar_win();

private:
    Ui::calendar_win *ui;
    QWidget* c_parent;

};

#endif // CALENDAR_WIN_H
