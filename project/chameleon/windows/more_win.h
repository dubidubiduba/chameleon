#ifndef MORE_WIN_H
#define MORE_WIN_H

#include <QWidget>
#include <QFormLayout>
#include <QPushButton>
namespace Ui {
class more_win;
}

class more_win : public QWidget
{
    Q_OBJECT

public:
    explicit more_win(QWidget *parent = nullptr);
    ~more_win();
    void initButton(QWidget* parent);

private:
    Ui::more_win *ui;

    QPushButton* btn_weather;
    QPushButton* btn_calendar;
    QPushButton* btn_clock;
};

#endif // MORE_WIN_H
