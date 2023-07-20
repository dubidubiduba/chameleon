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
    explicit dress_win(QWidget *parent=nullptr);
    ~dress_win();
    void close();

private:
    Ui::dress_win *ui;
    QWidget *m_parent;

};

#endif // DRESS_WIN_H
