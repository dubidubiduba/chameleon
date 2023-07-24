#include "more_win.h"
#include "ui_more_win.h"
#include<QScreen>
#include "note_win.h"

more_win::more_win(QWidget *parent,QWidget* p) :
    QWidget(parent),
    ui(new Ui::more_win)
{
    ui->setupUi(this);
    m_parent = p;
    initWindow();
    initBtn();
    initConnect();

    Calendar=new calendar_win(nullptr,this);
    notepad = new note_win(nullptr, this);

}

more_win::~more_win()
{
    delete ui;
    delete Calendar;
    delete notepad;

}
/*
在这里添加扩展功能的方式：
    添加对应按钮，并在initconnect()中写好槽函数，参考其他按钮的槽函数，在initButton()中初始化按钮
    在moveButtons(int speed,int flag)中写好滚轮移动的操作，参考其他按钮
    如果需要窗口，请先在.h文件中声明窗口指针
    
  以上步骤都完成后，你还需要在chameleon.cpp中的析构函数、winstatus()、mouseMoveEvent(QMouseEvent *event)处完成对应的操作
*/
void more_win::initWindow()
{
    int win_width = 80;
    int win_height = 220;
    int X = m_parent->geometry().x() - win_width;
    int Y = m_parent->geometry().y()+m_parent->geometry().height()/2-win_height/2;
    this->setGeometry(X,Y,win_width,win_height);
    setWindowOpacity(0.8);//设置透明度
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
}
void more_win::initBtn()
{
    btn_calendar    =new QPushButton(this);
    btn_clock       =new QPushButton(this);
    btn_weather     =new QPushButton(this);
    btn_note     =new QPushButton(this);
    btn_music     =new QPushButton(this);
    btn_screensh=new QPushButton(this);

    setStyleSheet("QPushButton{border:4px solid black;"
                  "background-color:rgb(173, 216, 230);border-radius: 10px;}"
                  "QPushButton::hover{background-color:rgb(180,255,255);}"
                  "QPushButton:pressed{background-color:rgb(60,170,150);}");

    btn_screensh->setIcon(QIcon(":/src/images/icon/screenshot.png"));
    btn_calendar->setIcon(QIcon(":/src/images/icon/calendar.png"));
    btn_clock->setIcon(QIcon(":/src/images/icon/clock.png"));
    btn_weather->setIcon(QIcon(":/src/images/icon/weather.png"));
    btn_note->setIcon(QIcon(":/src/images/icon/note.png"));
    btn_music->setIcon(QIcon(":/src/images/icon/music.png"));

    setButtonsGeo(btn_screensh);
    setButtonsGeo(btn_calendar);
    setButtonsGeo(btn_clock);
    setButtonsGeo(btn_weather);
    setButtonsGeo(btn_note);
    setButtonsGeo(btn_music);
}

void more_win::setButtonsGeo(QPushButton* button)
{
    btnSize = this->geometry().width()/1.5;
    double X = this->frameGeometry().width()/2 -  btnSize/2;
    static int Y = 0;
    QSize temp(btnSize/1.2,btnSize/1.2);
    button->setIconSize(temp);  //
    button->setGeometry(X,Y,btnSize,btnSize);
    Y += btnSize + 2;
}
void more_win::initConnect()
{
    connect(btn_calendar,&QPushButton::clicked,this,&more_win::calendarClicked);
    connect(btn_clock,&QPushButton::clicked,this,&more_win::clockClicked);
    connect(btn_weather,&QPushButton::clicked,this,&more_win::weatherClicked);
    connect(btn_note,&QPushButton::clicked,this,&more_win::notepadClicked);
    connect(btn_screensh,&QPushButton::clicked,this,&more_win::screenshotClicked);

}

void more_win::moveButtons(int speed,int flag)
{
    int temp = speed*flag;
    double X = this->frameGeometry().width()/2 -  btnSize/2;
    btn_calendar->move(X,btn_calendar->y()+temp);
    btn_clock->move(X,btn_clock->y()+temp);
    btn_weather->move(X,btn_weather->y()+temp);
    btn_note->move(X,btn_note->y()+temp);
    btn_music->move(X,btn_music->y()+temp);
    btn_screensh->move(X,btn_screensh->y()+temp);
}

void more_win::winstatus()
{
    Calendar->setVisible(winSwitch);
    notepad->setVisible(winSwitch);
}


/*---------------------------------槽函数部分-----------------------------------*/
/*
    点击对应按钮实现对应的功能，如果需要弹出窗口，窗口类的命名规范参考windows目录下的那三个窗口

*/
void more_win::weatherClicked()
{
    winstatus();
    QSoundEffect *clicksound = new QSoundEffect(this);
    clicksound->setSource(QUrl("qrc:/src/images/icon/click.wav"));  // 使用 "qrc:" 前缀指定资源文件路径
    clicksound->setVolume(0.5);
    clicksound->play();
}

void more_win::notepadClicked()
{
    winstatus();
    QSoundEffect *clicksound = new QSoundEffect(this);
    clicksound->setSource(QUrl("qrc:/src/images/icon/click.wav"));  // 使用 "qrc:" 前缀指定资源文件路径
    clicksound->setVolume(0.5);
    clicksound->play();
    if(notepad->isHidden())
    {   notepad->move(x()-notepad->frameGeometry().width(),y()+frameGeometry().height()/2-notepad->frameGeometry().height()/2);
        notepad->show();
    }
    else
    {
        notepad->hide();
    }
}

void more_win::clockClicked()
{
    winstatus();
    QSoundEffect *clicksound = new QSoundEffect(this);
    clicksound->setSource(QUrl("qrc:/src/images/icon/click.wav"));  // 使用 "qrc:" 前缀指定资源文件路径
    clicksound->setVolume(0.5);
    clicksound->play();
}

void more_win::calendarClicked()
{
    winstatus();
    QSoundEffect *clicksound = new QSoundEffect(this);
    clicksound->setSource(QUrl("qrc:/src/images/icon/click.wav"));  // 使用 "qrc:" 前缀指定资源文件路径
    clicksound->setVolume(0.5);
    clicksound->play();

    if(Calendar->isHidden())
    {   Calendar->move(x()-Calendar->frameGeometry().width(),y()+frameGeometry().height()/2-Calendar->frameGeometry().height()/2);
        Calendar->show();
    }
    else
    {
        Calendar->hide();
    }

}
void more_win::screenshotClicked()
{
    QSoundEffect *clicksound = new QSoundEffect(this);
    clicksound->setSource(QUrl("qrc:/src/images/icon/click.wav"));  // 使用 "qrc:" 前缀指定资源文件路径
    clicksound->setVolume(0.5);
    clicksound->play();
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen)
    {
        QPixmap screenshot = screen->grabWindow(0);

        QString filePath = QFileDialog::getSaveFileName(this, "Save Screenshot", "", "Images (*.png)");
        if (!filePath.isEmpty())
        {
            screenshot.save(filePath);
        }
    }
}


/*--------------------------------------------------------------------*/
void more_win::wheelEvent(QWheelEvent *event)
{
    static int speed = 40;//滚动速度
    if(event->delta()<0)
    {
        if(btn_music->y()+btnSize >= this->height())moveButtons(speed,-1);
    }
    else
    {
        if(btn_screensh->y() != 0) moveButtons(speed,1);
    }
    update();
}

