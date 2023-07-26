#ifndef NCS_H
#define NCS_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMovie>
#include "ResizableLabel.h"

class NCS : public QObject
{
    Q_OBJECT
public:
    NCS(QWidget* parent);
    ~NCS();
    void initBody();
    QLabel *body;

private:
    QWidget *m_parent;
    QMovie *m_movie;
};

#endif // NCS_H
