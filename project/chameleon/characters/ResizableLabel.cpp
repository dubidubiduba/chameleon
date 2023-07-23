#include "ResizableLabel.h"

ResizableLabel::ResizableLabel(QWidget *parent)
    : QLabel(parent) {
    setScaledContents(true); // 设置为自动适应内容大小
}

void ResizableLabel::resizeEvent(QResizeEvent *event) {
    QLabel::resizeEvent(event);
    const QPixmap *pixmap = this->pixmap();
    if (pixmap) {
        const QSize& labelSize = this->size();
        const QSize& pixmapSize = pixmap->size();

        int width = pixmapSize.width();
        int height = pixmapSize.height();

        // 根据比例重新设置大小
        if (width > labelSize.width() || height > labelSize.height()) {
            double widthRatio = static_cast<double>(labelSize.width()) / static_cast<double>(width);
            double heightRatio = static_cast<double>(labelSize.height()) / static_cast<double>(height);
            double ratio = qMin(widthRatio, heightRatio);
            width *= ratio;
            height *= ratio;
        }

        setPixmap(pixmap->scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

