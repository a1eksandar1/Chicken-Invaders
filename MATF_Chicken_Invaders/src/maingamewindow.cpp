#include "headers/maingamewindow.h"
#include "ui_maingamewindow.h"
#include <QScreen>
#include <QFocusEvent>

#include "headers/bigegg.h"
#include "headers/bigeggbullets.h"
#include "headers/quitgamewindow.h"

MainGameWindow::MainGameWindow(MainWindow *parent) :
    mw(parent),
    ui(new Ui::MainGameWindow),
    scene(new QGraphicsScene(this)),
    scroll(new QScrollBar),
    fly_speed(20000),
    spaceship(new Spaceship(mw)),
    timer(new QTimer(this)),
    message(new QGraphicsPixmapItem),
    waveCounter(0),
    openedQuitWindow(false)
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
    background->setPixmap(bkgnd.scaled(width, height*3));

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

void MainGameWindow::removeMessage()
{
    scene->removeItem(message);
    if(waveCounter >= 2){
        emit gameStart();
    }
}

void MainGameWindow::slot_level1()
{
    if(waveCounter == 1 ){
//        SideChickenGame *scg = new SideChickenGame(mw, scene, 15);
//        scg->start();
//        connect(scg, &SideChickenGame::closeSideChickenGame, this, &MainGameWindow::setUserMessage);
//        ChickenMatrixGame *cmg = new ChickenMatrixGame(mw, scene, 9, 4);
//        cmg->start();
//        connect(cmg, &ChickenMatrixGame::closeChickenMatrixGame, this, &MainGameWindow::setUserMessage);
//        EggChickenGame *ecg = new EggChickenGame(mw, scene, 30);
//        ecg->start();
//        connect(ecg, &EggChickenGame::closeEggChickenGame, this, &MainGameWindow::setUserMessage);
//        WaveChickenGame *wcg = new WaveChickenGame(mw, scene, 13);
//        wcg->start();
//        connect(wcg, &WaveChickenGame::closeWaveChickenGame, this, &MainGameWindow::setUserMessage);
        PlanetChickenGame *pcg = new PlanetChickenGame(mw, scene, 12, 2);
        pcg->start();
        connect(pcg, &PlanetChickenGame::closePlanetChickenGame, this, &MainGameWindow::setUserMessage);
    }
    else if(waveCounter == 2){
        sideMeteorShowerGame *smsg = new sideMeteorShowerGame(mw,scene,2,2);
        smsg->start();
        connect(smsg, &sideMeteorShowerGame::closeSideMeteorShowerGame, this, &MainGameWindow::setUserMessage);
    }
    else if(waveCounter == 3){
        BossGame * bg = new BossGame(mw, scene, 1);
        bg->start();
        connect(bg, &BossGame::closeBossGame, this, &MainGameWindow::setUserMessage);
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

void MainGameWindow::endOfGame()
{
    mw->backGroundMusic->play();
    deleteLater();
}

void MainGameWindow::continueGame()
{
    mw->setFreezeScene(false);
    animation->start();
}

void MainGameWindow::victory()
{
    if(mw->getReachedLevel() == mw->getDesiredLevel())
        mw->setReachedLevel(mw->getReachedLevel()+1);
    mw->victorySound->stop();
    mw->backGroundMusic->play();
    mw->openChooseLevelWindow();
    deleteLater();
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
    QTimer::singleShot(3500, this, &MainGameWindow::slot_level1);

    connect(this, &MainGameWindow::gameStart, this, &MainGameWindow::slot_level1);

    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);
}

void MainGameWindow::level2()
{
    QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);
    QTimer::singleShot(0, this, &MainGameWindow::playPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::stopPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::slot_level1);

    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);
}

void MainGameWindow::level3()
{
    QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);
    QTimer::singleShot(0, this, &MainGameWindow::playPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::stopPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::slot_level1);

    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);
}

void MainGameWindow::level4()
{
    QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);
    QTimer::singleShot(0, this, &MainGameWindow::playPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::stopPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::slot_level1);

    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);
}

void MainGameWindow::level5()
{
    QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);
    QTimer::singleShot(0, this, &MainGameWindow::playPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::stopPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::slot_level1);

    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);
}

void MainGameWindow::level6()
{
    QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);
    QTimer::singleShot(0, this, &MainGameWindow::playPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::stopPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::slot_level1);

    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);
}

void MainGameWindow::level7()
{
    QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);
    QTimer::singleShot(0, this, &MainGameWindow::playPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::stopPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::slot_level1);

    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);
}

void MainGameWindow::level8()
{
    QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);
    QTimer::singleShot(0, this, &MainGameWindow::playPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::stopPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::slot_level1);

    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);
}

void MainGameWindow::level9()
{
    QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);
    QTimer::singleShot(0, this, &MainGameWindow::playPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::stopPrepareMusic);
    QTimer::singleShot(3500, this, &MainGameWindow::slot_level1);

    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);
}

void MainGameWindow::start()
{
    spaceship->setStartingPosition(width/2-65, height-120);

    spaceship->setPos(spaceship->getStartingXPos(), spaceship->getStartingYPos());
    scene->addItem(spaceship);
    mw->getScore()->setPos(pos().x()+20, pos().y());

    // lisov menjao ovaj deo koda
    mw->getScore()->setPos(pos().x()+10, pos().y());
    scene->addItem(mw->getScore());
    mw->getLives()->setPos(width - 130, -20);
    // mw->getLives()->set2LivesPic(); ovako menjamo izgled kada se izgubi zivot
    scene->addItem(mw->getLives());
    // do ovde

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

void MainGameWindow::setUserMessage()
{
    if(waveCounter == 0 && mw->getDesiredLevel() == 1){
        QPixmap pm(":/images/backgrounds/wave1.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 1 && mw->getDesiredLevel() == 1){
        QPixmap pm(":/images/backgrounds/wave2.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 2 && mw->getDesiredLevel() == 1){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 0 && mw->getDesiredLevel() == 2){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 1 && mw->getDesiredLevel() == 2){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 2 && mw->getDesiredLevel() == 2){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 0 && mw->getDesiredLevel() == 3){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 1 && mw->getDesiredLevel() == 3){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 2 && mw->getDesiredLevel() == 3){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 0 && mw->getDesiredLevel() == 4){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 1 && mw->getDesiredLevel() == 4){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 2 && mw->getDesiredLevel() == 4){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 0 && mw->getDesiredLevel() == 5){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 1 && mw->getDesiredLevel() == 5){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 2 && mw->getDesiredLevel() == 5){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 0 && mw->getDesiredLevel() == 6){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 1 && mw->getDesiredLevel() == 6){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 2 && mw->getDesiredLevel() == 6){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter == 0 && mw->getDesiredLevel() == 7){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }

    else if(waveCounter == 1 && mw->getDesiredLevel() == 7){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }

    else if(waveCounter == 2 && mw->getDesiredLevel() == 7){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }

    else if(waveCounter == 0 && mw->getDesiredLevel() == 8){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }

    else if(waveCounter == 1 && mw->getDesiredLevel() == 8){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }

    else if(waveCounter == 2 && mw->getDesiredLevel() == 8){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }

    else if(waveCounter == 0 && mw->getDesiredLevel() == 9){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }

    else if(waveCounter == 1 && mw->getDesiredLevel() == 9){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }

    else if(waveCounter == 2 && mw->getDesiredLevel() == 9){
        QPixmap pm(":/images/backgrounds/wave3.png");
        message->setPixmap(pm.scaled(width,height));
    }
    else if(waveCounter % 3  == 0 && waveCounter != 0){
        QPixmap pm(":/images/backgrounds/congratulations.png");
        message->setPixmap(pm.scaled(width,height));

        message->setPos(0, 0);
        scene->addItem(message);
        mw->victorySound->play();

        QTimer::singleShot(4000, this, &MainGameWindow::victory);
        return;
    }

    message->setPos(0, 0);
    scene->addItem(message);
    ++waveCounter;

    QTimer::singleShot(3000, this, &MainGameWindow::removeMessage);
}

void MainGameWindow::openQuitGameWindow()
{
    QuitGameWindow *qgw = new QuitGameWindow(this);
    qgw->setWindowFlags(Qt::CustomizeWindowHint);
    //qgw->setAttribute(Qt::WA_TranslucentBackground);
    openedQuitWindow = true;

    qgw->setFocus();
    qgw->exec();
}

void MainGameWindow::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Escape){
        mw->setFreezeScene(true);
        animation->pause();
        mw->pauseAllSounds();
        openQuitGameWindow();
    }
    if(event->key() == Qt::Key_Space){
        if(!mw->getFreezeScene()){
            if(spaceship->getThrowingAllowed()){
                spaceship->setThrowingAllowed(false);
                spaceship->throw_projectile();
            }
        }
    }
    if(event->key() == Qt::Key_A){ // change it to be LeftArrow
        if(!mw->getFreezeScene()){
            spaceship->setDirection(-1);
            spaceship->start_moving_timer();
        }
    }
    if(event->key() == Qt::Key_D){ // change it to be LeftArrow
        if(!mw->getFreezeScene()){
            spaceship->setDirection(1);
            spaceship->start_moving_timer();
        }
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
