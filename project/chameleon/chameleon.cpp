#include "chameleon.h"
#include "ui_chameleon.h"
//库添加在.h文件
chameleon::chameleon(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chameleon)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);//去掉窗口标题   这里为了测试方便，就保留了边框
    int coordX,coordY;//桌面坐标
    QFile file("./file/file.dat");                                                    //文件的操作
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    if(file.isOpen())//读取体型\相对桌面坐标
        in>>size>>coordX>>coordY;
    else{
        size = 500;
        coordX = x();
        coordY = y();
    }
    file.close();
    move(coordX,coordY);
    //初始化操作
    initWindow();

    More = new more_win;
    Dress =  new dress_win;
    S = new slime(this);
    Set=new setwin(nullptr,this);
    Set->setSize(size);
    initButton(1,0);
    initLayout();
}
chameleon::~chameleon()
{
    delete ui;
    delete S;
}

/*--------------------------------------初始化部分--------------------------------------------*/
void chameleon::initWindow()//初始化主窗口
{
    //获取屏幕的宽和高
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    ScreenWidth = screenGeometry.width();
    ScreenHeight = screenGeometry.height();
    
    //win_width = screenGeometry.width()/3.5;
    //win_height = screenGeometry.height()/3.5;
    this->resize(win_width,win_height);
    int winX= ScreenWidth-this->frameGeometry().width() - ScreenWidth/12;
    int winY = ScreenHeight-this->frameGeometry().height() - ScreenHeight/12;
    this->move(winX,winY);
    //窗口置顶、透明
    setAttribute(Qt::WA_TranslucentBackground);//设置背景透明
    Qt::WindowFlags m_flags = windowFlags();
    setWindowFlags(m_flags|Qt::WindowStaysOnTopHint);

}


void chameleon::initButton(bool a,double b)  //初始化按钮
{
    btn_exit = new QPushButton(this);
    btn_dress = new QPushButton(this);
    btn_more = new QPushButton(this);
    btn_setting = new QPushButton(this);
    btn_test = new QPushButton("test",this);
    //加载按钮图标
    btn_exit->setIcon(QIcon(":/src/images/icon/close.png"));
    btn_dress->setIcon(QIcon(":/src/images/icon/dress.png"));
    btn_more->setIcon(QIcon(":/src/images/icon/more.png"));
    btn_setting->setIcon(QIcon(":/src/images/icon/setting.png"));
    //设置按钮的大小
    int btn_size = 64;
    btn_exit->setFixedSize(btn_size,btn_size);
    btn_dress->setFixedSize(btn_size,btn_size);
    btn_more->setFixedSize(btn_size,btn_size);
    btn_setting->setFixedSize(btn_size,btn_size);
    //设置按钮图标的大小
    QSize temp(btn_size/1.2,btn_size/1.2);
    btn_exit->setIconSize(temp);
    btn_dress->setIconSize(temp);
    btn_more->setIconSize(temp);
    btn_setting->setIconSize(temp);
    //样式表
    setStyleSheet("QPushButton{border:4px solid black;"
                  "background-color:rgb(200,210,255);border-radius: 10px;}"
                  "QPushButton::hover{background-color:rgb(170,200,255);}"
                  "QPushButton:pressed{background-color:rgb(60,70,200);}");
    if (a==1)
    {
    btn_setting->move(0,387-btn_size+20);
    btn_more->move(0,387-btn_size*2.2+20);
    btn_dress->move(0,387-btn_size*3.4+20);
    btn_exit->move(0,387-btn_size*4.6+20);
    }
    else
    {
    btn_setting->move(0+b,387-btn_size+b);
    btn_more->move(0+b,387-btn_size*2.2+b);
    btn_dress->move(0+b,387-btn_size*3.4+b);
    btn_exit->move(0+b,387-btn_size*4.6+b);
    }
        //槽函数绑定
    connect(btn_exit, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
    connect(btn_dress,&QPushButton::clicked,this,&chameleon::dressClicked);
    connect(btn_more,&QPushButton::clicked,this,&chameleon::moreClicked);
    connect(btn_setting,&QPushButton::clicked,this,&chameleon::settingClicked);
    connect(btn_test,&QPushButton::clicked,this,&chameleon::testClicked);
}
void chameleon::initLayout()//初始化布局管理器
{
    body_part = new QHBoxLayout;
    body_part->addWidget(S->body);
    this->setLayout(body_part);
}




/*----------------------------------------槽函数部分------------------------------------------*/

/*对于弹出窗口的槽函数，窗口中具体功能的实现请在对应的窗口类中写，这里只负责弹出窗口*/
void chameleon::dressClicked()  //展示出可选的角色，这里可以使用按钮组QButtonGroup（haro用的是这个），或者一些别的。。
{
    if(Dress->isHidden())
    {
        Dress->show();
    }
    else
    {
        Dress->hide();
    }

}

void chameleon::moreClicked()  //弹出一个包含了更多功能按钮的菜单
{
    if(More->isHidden())
    {
        More->show();
    }
    else
    {
        More->hide();
    }
}

void chameleon::settingClicked()  //设置大小   设置的方式可以参考haro，也可以用其他方式，如果需要弹出窗口，请为这个窗口设置一个类，添加到windows目录中
//注意，当窗口大小变化时，左侧按钮的位置许不太美观，也许需要你花一些精力想办法解决，可以修改initButton函数的内容
{
    if(Set->isHidden()){
        //移动窗口坐标↓
        Set->move(x()+frameGeometry().width()/2-230
                            -Set->frameGeometry().width(),
                        y()+frameGeometry().height()/2
                            -Set->frameGeometry().height()/2);

        Set->show();
    }
    else
        Set->hide();

}

void chameleon::testClicked()  //提供了一个共用的测试按钮，可以用来测试一些小功能 ，合并代码时请恢复
{

}

/*------------------------------------------事件部分------------------------------------------*/
//这里需要一个鼠标左键能拖动窗口移动的功能，事件这一块puck还是小白 所以就没写函数头了



















