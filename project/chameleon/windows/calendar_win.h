#ifndef CALENDAR_WIN_H
#define CALENDAR_WIN_H

#include <QMainWindow>

namespace Ui {
class calendar_win;
}

class calendar_win : public QMainWindow
{
    Q_OBJECT

public:
    explicit calendar_win(QWidget *parent = nullptr);
    ~calendar_win();

private:
    Ui::calendar_win *ui;
};

#endif // CALENDAR_WIN_H
