#include "chameleon.h"
#include <QApplication>
#include <QSystemTrayIcon>
#include <QMenu>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chameleon w;
    w.show();
    a.setQuitOnLastWindowClosed(false);

    // 创建系统托盘图标
    QSystemTrayIcon trayIcon(QIcon(":/src/images/icon/chameleon.png"), &a);
    trayIcon.setToolTip("My Application");

    // 创建菜单并添加退出动作
    QMenu *menu = new QMenu(&w);
    QAction *exitAction = menu->addAction("退出");
    QObject::connect(exitAction, &QAction::triggered, &a, &QCoreApplication::quit);

    trayIcon.setContextMenu(menu);

    // 显示系统托盘图标
    trayIcon.show();

    return a.exec();
}
