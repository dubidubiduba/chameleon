#include "chameleon.h"
#include "ui_chameleon.h"
//库添加在.h文件
chameleon::chameleon(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chameleon)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);//去掉窗口标题
    int coordX,coordY;//桌面坐标
    QFile file("./file/file.dat");                                                    //文件的操作
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    if(file.isOpen())//读取体型\相对桌面坐标
        in>>size>>coordX>>coordY;
    else{
        size = 100;
        coordX = x();
        coordY = y();
    }
    file.close();
    move(coordX,coordY);

    //初始化操作
    initWindow();

    More = new more_win(this,this);
    Dress =  new dress_win(this,this);
    Set = new setwin(this,this);

    _rinai = new riNai(this);
    _rinai->body->hide();
    _haro = new haro(this);  //初始角色  主窗口和角色有关联的只有这里
    body_part = new QVBoxLayout(this);
    body_part->addWidget(_haro->bodyImage);

    Set->setSize(size);
    initButton();
}
//不是继承自widget的对象记得在这里释放
chameleon::~chameleon()
{
    delete _rinai;
    delete _haro;
    delete More;
    delete Dress;
    delete Set;
    delete ui;
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

void chameleon::initButton()  //初始化按钮
{
    btn_exit = new QPushButton(this);
    btn_dress = new QPushButton(this);
    btn_more = new QPushButton(this);
    btn_setting = new QPushButton(this);
    //
    btn_exit->setWindowFlags(Qt::WindowStaysOnTopHint);
    btn_dress->setWindowFlags(Qt::WindowStaysOnTopHint);
    btn_more->setWindowFlags(Qt::WindowStaysOnTopHint);
    btn_setting->setWindowFlags(Qt::WindowStaysOnTopHint);
    //加载按钮图标
    btn_exit->setIcon(QIcon(":/src/images/icon/close.png"));
    btn_dress->setIcon(QIcon(":/src/images/icon/dress.png"));
    btn_more->setIcon(QIcon(":/src/images/icon/more.png"));
    btn_setting->setIcon(QIcon(":/src/images/icon/setting.png"));
    //设置按钮的大小
    int btn_size = 50;
    btn_exit->setFixedSize(btn_size,btn_size);
    btn_dress->setFixedSize(btn_size,btn_size);
    btn_more->setFixedSize(btn_size,btn_size);
    btn_setting->setFixedSize(btn_size,btn_size);
    //设置按钮图标的大小
    QSize temp(btn_size/2,btn_size/2);
    btn_exit->setIconSize(temp);
    btn_dress->setIconSize(temp);
    btn_more->setIconSize(temp);
    btn_setting->setIconSize(temp);
    //样式表
    setStyleSheet("QPushButton{border:4px solid black;"
                  "background-color:rgb(173, 216, 230);border-radius: 10px;}"
                  "QPushButton::hover{background-color:rgb(180,255,255);}"
                  "QPushButton:pressed{background-color:rgb(60,170,150);}");
    // 获取窗口的宽度和高度
    int windowWidth = this->width();      // 窗口的宽度
    int windowHeight = this->height();    // 窗口的高度

    btn_setting->move(0,windowHeight/2+70);
    btn_more->move(0,windowHeight/2+8);
    btn_dress->move(0,windowHeight/2-58);
    btn_exit->move(0,windowHeight/2-120);

        //槽函数绑定
    connect(btn_exit, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
    connect(btn_dress,&QPushButton::clicked,this,&chameleon::dressClicked);
    connect(btn_more,&QPushButton::clicked,this,&chameleon::moreClicked);
    connect(btn_setting,&QPushButton::clicked,this,&chameleon::settingClicked);
    //初始化按钮显示
    btnSwitch1 = 0;
    btnSwitch2 = 0;
    btnstatus();
}
void chameleon::reinitButton()
{
    QRect windowGeometry=this->geometry();

    int windowX = windowGeometry.x(); // 获取窗口的横坐标
    int windowY = windowGeometry.y(); // 获取窗口的纵坐标

    // 获取窗口的宽度和高度
    int windowWidth = this->width();      // 窗口的宽度
    int windowHeight = this->height();    // 窗口的高度

    QRect buttonRect1 = btn_setting->geometry();
    int btn_setting_x = buttonRect1.x();  // 按钮的 x 坐标
    int btn_setting_y = buttonRect1.y();  // 按钮的 y 坐标
    QRect buttonRect2 = btn_more ->geometry();
    int btn_more_x = buttonRect2.x();  // 按钮的 x 坐标
    int btn_more_y = buttonRect2.y();  // 按钮的 y 坐标
    QRect buttonRect3 = btn_more ->geometry();
    int btn_dress_x = buttonRect3.x();  // 按钮的 x 坐标
    int btn_dress_y = buttonRect3.y();  // 按钮的 y 坐标
    QRect buttonRect4 = btn_more ->geometry();
    int btn_exit_x = buttonRect4.x();  // 按钮的 x 坐标
    int btn_exit_y = buttonRect4.y();  // 按钮的 y 坐标
    int temp1=387-64+20;
    int temp2=387-64*2.2+20;
    int temp3=387-64*3.4+20;
    int temp4=387-64*4.6+20;

//    btn_exit->setFixedSize(64/4,64/4);
//    btn_dress->setFixedSize(64/4,64/4);
//    btn_more->setFixedSize(64/4,64/4);
//    btn_setting->setFixedSize(64/4,64/4);

//    QSize temp(64/4,64/4);
//    btn_exit->setIconSize(temp);
//    btn_dress->setIconSize(temp);
//    btn_more->setIconSize(temp);
//    btn_setting->setIconSize(temp);

    //    if()
    //    if(b<0)
    //    {
    //        temp1=buttonRect1.y();
    //        temp2=buttonRect2.y();
    //        temp3=buttonRect3.y();
    //        temp4=buttonRect4.y();
    //    }
    //    btn_setting->move(buttonRect1.x()+a,temp1+b);
    //    btn_more->move(buttonRect2.x()+a,temp2+b);
    //    btn_dress->move(buttonRect3.x()+a,temp3+b);
    //    btn_exit->move(buttonRect4.x()+a,temp4+b);
    btn_setting->move(0,windowHeight/2+70);
    btn_more->move(0,windowHeight/2+8);
    btn_dress->move(0,windowHeight/2-58);
    btn_exit->move(0,windowHeight/2-120);


}
void chameleon::clearCharacters()
{
    if (_haro && body_part->indexOf(_haro->bodyImage) != -1) {
        // _haro 在布局中
        body_part->removeWidget(_haro->bodyImage);
        _haro->bodyImage->hide();
    }

    if (_rinai && body_part->indexOf(_rinai->body) != -1) {
        // _rinai 在布局中
        body_part->removeWidget(_rinai->body);
        _rinai->body->hide();
    }
}


/*----------------------------------------槽函数部分------------------------------------------*/

/*对于弹出窗口的槽函数，窗口中具体功能的实现请在对应的窗口类中写，这里只负责弹出窗口*/
void chameleon::dressClicked()  //展示出可选的角色，这里可以使用按钮组QButtonGroup（haro用的是这个），或者一些别的。。
{
    if(Dress->isHidden())
    {

        QList<QWidget *> topLevelWidgets = QApplication::topLevelWidgets();
        for (QWidget *widget : topLevelWidgets)
        {
            if (widget != this)
                widget->close();
        }
        Dress->initWindow();
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
        QList<QWidget *> topLevelWidgets = QApplication::topLevelWidgets();
        for (QWidget *widget : topLevelWidgets)
        {
            if (widget != this)
                widget->close();
        }
        More->initWindow();
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
        QList<QWidget *> topLevelWidgets = QApplication::topLevelWidgets();
        for (QWidget *widget : topLevelWidgets)
        {
            if (widget != this)
                widget->close();
        }
        //移动窗口坐标
        /*
        Set->move(x()+frameGeometry().width()/2-230
                            -Set->frameGeometry().width(),
                        y()+frameGeometry().height()/2
                            -Set->frameGeometry().height()/2);
        */
        Set->move(x()-Set->geometry().width()-100,y()+geometry().height()/2-Set->geometry().height()/2);
        Set->show();
    }
    else
        Set->hide();

}

/*------------------------------------------事件部分------------------------------------------*/
//这里需要一个鼠标左键能拖动窗口移动的功能，事件这一块puck还是小白 所以就没写函数头了
void chameleon::btnstatus()//设置显示状态
{
    btn_exit->setVisible(btnSwitch1);
    btn_dress->setVisible(btnSwitch1);
    btn_more->setVisible(btnSwitch1);
    btn_setting->setVisible(btnSwitch1);
}

void chameleon::mousePressEvent(QMouseEvent *event)//鼠标按压时触发该事件，仅触发一次
{
    if(event->button() == Qt::LeftButton)
    {
        startPos = event->pos();//pos函数返回鼠标相对于当前窗口的位置
        isMousePressed = true;
    }
    else if(event->button() == Qt::RightButton)
    {
        if(btnSwitch1)//如果是显示的就置为不显示
        {
            btnSwitch1 = 0;
        }
        else//否则就显示
        {
            btnSwitch1 = 1;
        }
        btnstatus();
    }
}

void chameleon::mouseMoveEvent(QMouseEvent *event)//在鼠标移动时会被多次调用
{
    if (isMousePressed) {
        QPoint endPos = event->pos();           //鼠标瞬时移动某时刻相对于窗口位置
        QPoint dist = endPos - startPos;        //以鼠标较起始位置的偏移量计算窗口落点的偏移量
        move(x()+dist.x(), y()+dist.y());       //x()和y()是记录窗口相对于父窗口的位置，默认为0，因此此处move()效果为直接将窗口位移到落点处
        Set->move(x()-Set->width()-100  ,  y()+height()/2-Set->height()/2);
        More->move(x() - More->width()  ,  y()+height()/2-More->height()/2);
        Dress->move(x()-Dress->width()  ,  y()+height()/2-Dress->height()/2);
    }
}

void chameleon::mouseReleaseEvent(QMouseEvent *event)//此处必须要带参数，否则会因为虚函数的继承问题报错
{
    isMousePressed = false;
}


















