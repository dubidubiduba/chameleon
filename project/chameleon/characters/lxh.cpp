#include "lxh.h"

LXH::LXH(QWidget* parent)
{
    m_parent = parent;
    initBody();
}

LXH::~LXH()
{
    delete m_movie;
}

void LXH::initBody()
{
    body = new ResizableLabel(m_parent);
    m_movie = new QMovie(":/src/images/LXH-images/lxh.gif"); // 替换为GIF图像的路径

    body->setMovie(m_movie);
    m_movie->start();
}


