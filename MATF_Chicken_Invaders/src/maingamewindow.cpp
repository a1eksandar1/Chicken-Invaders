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
    if(localLevelCounter >= 2){
        emit gameStart();
    }
}

void MainGameWindow::chickenMatrixGame()
{
    ChickenMatrixGame *cMatrixGame = new ChickenMatrixGame(mw, scene, 8,3);
    cMatrixGame->start();
    connect(cMatrixGame, &ChickenMatrixGame::closeChickenMatrixGame, this, &MainGameWindow::setUserMessage);
}

void MainGameWindow::meteorShowerGame()
{
    if(localLevelCounter == 2){
        MeteorShowerGame *mShowerGame = new MeteorShowerGame(mw, scene, 7, 5);
        mShowerGame->start();
        connect(mShowerGame, &MeteorShowerGame::closeMeteorShowerGame, this, &MainGameWindow::setUserMessage);
    }
}

void MainGameWindow::SideMeteorShowerGame()
{
    if(localLevelCounter == 3){
        sideMeteorShowerGame * sideMShowerGame = new sideMeteorShowerGame(mw, scene, 7, 5);
        sideMShowerGame->start();
        connect(sideMShowerGame, &sideMeteorShowerGame::closeSideMeteorShowerGame, this, &MainGameWindow::setUserMessage);
    }
}

void MainGameWindow::stopPrepareMusic()
{
    mw->gamePrepareSound->stop();
}

void MainGameWindow::playPrepareMusic()
{
    mw->gamePrepareSound->play();
}

void MainGameWindow::setUserMessage()
{
    if(localLevelCounter == 0){
        QPixmap pm(":/images/backgrounds/wave1_1.png");
        message->setPixmap(pm);
    }
    else if(localLevelCounter == 1){
        QPixmap pm(":/images/backgrounds/wave2.png");
        message->setPixmap(pm);
    }
    else if(localLevelCounter == 2){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm);
    }

    message->setPos(width/3.5, height/5.5);
    scene->addItem(message);
    ++localLevelCounter;

    QTimer::singleShot(3000, this, &MainGameWindow::removeMessage);
}

void MainGameWindow::endOfGame()
{
    mw->backGroundMusic->play();
    deleteLater();
}

void MainGameWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape){
        for(size_t i=0, n = scene->items().size(); i<n; i++)
        {
            scene->items()[i]->setEnabled(false);
        }
        scene->clear();
        mw->backGroundMusic->play();
        mw->gamePrepareSound->stop();
        delete this;
    }
    if(event->key() == Qt::Key_Space){
        if(spaceship->getThrowingAllowed()){
            spaceship->setThrowingAllowed(false);
            spaceship->throw_projectile();
        }
    }
    if(event->key() == Qt::Key_A){ // change it to be LeftArrow
        spaceship->setDirection(-1);
        spaceship->start_moving_timer();
    }
    if(event->key() == Qt::Key_D){ // change it to be LeftArrow
        spaceship->setDirection(1);
        spaceship->start_moving_timer();
    }

    QWidget::keyPressEvent(event);
}

void MainGameWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_A: // change it to be LeftArrow
        spaceship->setDirection(0);
        spaceship->stop_moving_timer();
        break;
    case Qt::Key_D: // change it to be RightArrow
        spaceship->setDirection(0);
        spaceship->stop_moving_timer();
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
    message(new QGraphicsPixmapItem),
    localLevelCounter(0)
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

    scene->addItem(background);
    scene->setFocus();
    scene->setSceneRect(0,0,width-30,height-30);

    mw->backGroundMusic->stop();


    connect(spaceship, &Spaceship::spaceshipDestroyed, this, &MainGameWindow::endOfGame);
    start();
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

    QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);
    QTimer::singleShot(0, this, &MainGameWindow::playPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::stopPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::chickenMatrixGame);

    connect(this, &MainGameWindow::gameStart, this, &MainGameWindow::meteorShowerGame);
    connect(this, &MainGameWindow::gameStart, this, &MainGameWindow::SideMeteorShowerGame);

    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);
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
