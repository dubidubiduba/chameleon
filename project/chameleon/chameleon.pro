QT       += core gui multimedia
QT       += core gui xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    characters/ResizableLabel.cpp \
    characters/haro.cpp \
    characters/lxh.cpp \
    characters/ncs.cpp \
    characters/rinai.cpp \
    main.cpp \
    chameleon.cpp \
    windows/calendar_win.cpp \
    windows/dress_win.cpp \
    windows/filesdialog.cpp \
    windows/haro_dress.cpp \
    windows/listwidget.cpp \
    windows/more_win.cpp \
    windows/mycalendar.cpp \
 windows/notewindow.cpp \
    windows/schedule.cpp \
    windows/scheduledialog.cpp \
    windows/schedulemanager.cpp \
    windows/set_win.cpp

HEADERS += \
    chameleon.h \
    characters/ResizableLabel.h \
    characters/haro.h \
    characters/lxh.h \
    characters/ncs.h \
    characters/rinai.h \
    windows/calendar_win.h \
    windows/dress_win.h \
    windows/filesdialog.h \
    windows/haro_dress.h \
    windows/listwidget.h \
    windows/more_win.h \
    windows/mycalendar.h \
windows/notewindow.h \
    windows/schedule.h \
    windows/scheduledialog.h \
    windows/schedulemanager.h \
    windows/set_win.h \
    windows/utility.h

FORMS += \
    chameleon.ui \
    windows/calendar_win.ui \
    windows/dress_win.ui \
    windows/filesdialog.ui \
    windows/haro_dress.ui \
    windows/more_win.ui \
    windows/notewindow.ui \
    windows/scheduledialog.ui \
    windows/set_win.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
