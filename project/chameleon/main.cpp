#include "chameleon.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chameleon w;
    w.show();
    a.setQuitOnLastWindowClosed(false);
    return a.exec();
}
