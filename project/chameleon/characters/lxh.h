#ifndef LXH_H
#define LXH_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMovie>
#include "ResizableLabel.h"

class LXH : public QObject
{
    Q_OBJECT
public:
    LXH(QWidget* parent);
    ~LXH();
    void initBody();
    QLabel *body;

private:
    QWidget *m_parent;
    QMovie *m_movie;
};




#endif // LXH_H
