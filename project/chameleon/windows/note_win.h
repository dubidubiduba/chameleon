#ifndef NOTE_WIN_H
#define NOTE_WIN_H

#include <QWidget>

namespace Ui {
class note_win;
}

class note_win : public QWidget
{
    Q_OBJECT

public:
    explicit note_win(QWidget *parent = nullptr, QWidget* p = nullptr);
    void initWindow();
    ~note_win();

private:
    Ui::note_win *ui;
    QWidget* n_parent;
};

#endif // NOTE_WIN_H
