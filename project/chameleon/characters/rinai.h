#ifndef RINAI_H
#define RINAI_H

#include <QObject>
#include <QLabel>
#include <vector>
#include <QTimer>
#include <QDebug>
#include <QVBoxLayout>

class riNai : public QObject
{
    Q_OBJECT
public:
    explicit riNai(QWidget* parent);
    ~riNai();
    void bodyLoad();
    void initBody();
    void movement();
    void initDress();
    void Imageset(QLabel* image,QPixmap pixmap);

    QVBoxLayout* Body;
    QLabel* body;
private:

    QWidget* m_parent;
    std::vector<QPixmap> Bodys;
    QTimer* timer;

signals:

};

#endif // RINAI_H
