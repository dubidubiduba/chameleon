#pragma once

#include <QLabel>
#include <QMovie>

class ResizableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ResizableLabel(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;
};
