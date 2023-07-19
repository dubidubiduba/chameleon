#ifndef DRESS_WIN_H
#define DRESS_WIN_H

#include <QWidget>


namespace Ui {
class dress_win;
}

class dress_win : public QWidget
{
    Q_OBJECT

public:
    explicit dress_win(QWidget *parent = nullptr);
    ~dress_win();


private:
    Ui::dress_win *ui;
};

#endif // DRESS_WIN_H
