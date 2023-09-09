#include "ncs.h"

NCS::NCS(QWidget* parent)
{
    m_parent = parent;
    initBody();
}

NCS::~NCS()
{
    delete m_movie;
}

void NCS::initBody()
{
    body = new ResizableLabel(m_parent);
    m_movie = new QMovie(":/src/images/ncs-images/ncs.gif"); // 替换为GIF图像的路径

    body->setMovie(m_movie);
    m_movie->start();
}

