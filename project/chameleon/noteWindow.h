#ifndef NOTEWINDOW_H
#define NOTEWINDOW_H

#include <QMainWindow>

namespace Ui {
class noteWindow;
}

class noteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit noteWindow(QWidget *parent = nullptr);
    ~noteWindow();

private:
    Ui::noteWindow *ui;
};

#endif // NOTEWINDOW_H
