#include "headers/maingamewindow.h"
#include "ui_maingamewindow.h"
#include <QScreen>
#include "headers/chicken.h"

void MainGameWindow::slow_down()
{
    fly_speed = 20000;
    animation->setDuration(fly_speed);
}

void MainGameWindow::removeMessage()
{
    scene->removeItem(message);
}

void MainGameWindow::igra1PomocnaFunkcija()
{
    QVector<QVector<Chicken*>> chick;
    chick.resize(8);
    for (int i=0; i < 8; i++)
    {
        chick[i].resize(3);
    }

    for (int i=0; i < 8 ; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            chick[i][j] = new Chicken(mw,i,j);
            scene->addItem(chick[i][j]);
        }
    }

    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);
}

void MainGameWindow::stopPrepareMusic()
{
    mw->gamePrepareSound->stop();
}

void MainGameWindow::playPrepareMusic()
{
    mw->gamePrepareSound->play();
}

void MainGameWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        for(size_t i=0, n = scene->items().size(); i<n; i++)
        {
            scene->items()[i]->setEnabled(false);
        }
        scene->clear();
        mw->backGroundMusic->play();
        delete this;
        break;
    case Qt::Key_Space:
        if(spaceship->getThrowingAllowed()){
            spaceship->setThrowingAllowed(false);
            spaceship->throw_projectile();
        }
        break;
    case Qt::Key_A: // change it to be LeftArrow
        spaceship->move_left();
        break;
    case Qt::Key_D: // change it to be RightArrow
        spaceship->move_right();
        break;
    case Qt::Key_W: // change it to be UpArrow
        spaceship->move_up();
        break;
    case Qt::Key_S: // change it to be DownArrow
        spaceship->move_down();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

MainGameWindow::MainGameWindow(MainWindow *parent) :
    ui(new Ui::MainGameWindow),
    mw(parent),
    scene(new QGraphicsScene(this)),
    scroll(new QScrollBar),
    fly_speed(20000),
    spaceship(new Spaceship(mw)),
    timer(new QTimer(this)),
    message(new QGraphicsPixmapItem)
{
    ui->setupUi(this);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    ui->graphicsView->setScene(scene);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    height = screenGeometry.height();
    width = screenGeometry.width();

    scroll = ui->graphicsView->verticalScrollBar();

    QPixmap bkgnd(":/images/backgrounds/gameBackground.png");

    background = new AnimatedGraphicsItem;
    background->setPixmap(bkgnd);

    animation = new QPropertyAnimation(background, "pos");
    animation->setLoopCount(-1);
    animation->setDuration(fly_speed);
    animation->setStartValue(QPoint(0,-2*height));
    animation->setEndValue(QPoint(0,0));
    animation->start();

    //QTimer::singleShot(3000, this, &MainGameWindow::slow_down);

    scene->addItem(background);
    scene->setFocus();
    scene->setSceneRect(0,0,width-30,height-30);

    mw->backGroundMusic->stop();
}

MainGameWindow::~MainGameWindow()
{
    delete ui;
}

int MainGameWindow::getFly_speed() const
{
    return fly_speed;
}

void MainGameWindow::setFly_speed(int value)
{
    fly_speed = value;
}

void MainGameWindow::level1()
{
    QPixmap pm(":/images/backgrounds/wave1_1.png");
    message->setPixmap(pm);
    message->setPos(width/3.5, height/5.5);
    scene->addItem(message);

    QTimer::singleShot(0, this, &MainGameWindow::playPrepareMusic);
    QTimer::singleShot(3000, this, &MainGameWindow::removeMessage);
    QTimer::singleShot(3500, this, &MainGameWindow::stopPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::igra1PomocnaFunkcija);

}

void MainGameWindow::level2()
{

}

void MainGameWindow::level3()
{

}

void MainGameWindow::level4()
{

}

void MainGameWindow::level5()
{

}

void MainGameWindow::level6()
{

}

void MainGameWindow::level7()
{

}

void MainGameWindow::level8()
{

}

void MainGameWindow::level9()
{

}

void MainGameWindow::start()
{
    spaceship->setStartingPosition(width/2-65, height-120);

    spaceship->setPos(spaceship->getStartingXPos(), spaceship->getStartingYPos());
    scene->addItem(spaceship);

    if(mw->getDesiredLevel() == 1){
        level1();
    }
    else if(mw->getDesiredLevel() == 2){
        level2();
    }
    else if(mw->getDesiredLevel() == 3){
        level3();
    }
    else if(mw->getDesiredLevel() == 4){
        level4();
    }
    else if(mw->getDesiredLevel() == 5){
        level5();
    }
    else if(mw->getDesiredLevel() == 6){
        level6();
    }
    else if(mw->getDesiredLevel() == 7){
        level7();
    }
    else if(mw->getDesiredLevel() == 8){
        level8();
    }
    else if(mw->getDesiredLevel() == 9){
        level9();
    }
}
