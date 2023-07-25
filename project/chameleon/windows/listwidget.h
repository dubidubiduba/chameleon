#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include "utility.h"
#include <QObject>
#include <QListWidget>

class ListWidget : public QListWidget
{

public:
    explicit ListWidget(QWidget *parent = nullptr);
    void setFileslist(QVector<QUrl> *fileslist_);
    bool dragEnable;

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    QVector<QUrl>* fileslist;
};

#endif // LISTWIDGET_H
