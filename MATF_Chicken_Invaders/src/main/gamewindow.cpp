#include "headers/main_h/gamewindow.h"
#include "headers/enemies_h/chicken.h"
#include "headers/enemies_h/egg.h"
#include "headers/spaceship_h/projectile.h"
#include "headers/spaceship_h/spaceship.h"
#include "headers/enemies_h/bigegg.h"
#include "headers/enemies_h/bigeggbullets.h"
#include "ui_gamewindow.h"
#include <QDialog>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QScreen>
#include <QTimer>
#include "headers/games_h/chickenmatrixgame.h"
#include "headers/games_h/meteorshowergame.h"
#include "headers/games_h/sidemeteorshowergame.h"

void GameWindow::kraj(){
    close();
}
void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape){
        for(size_t i=0, n = scene->items().size(); i<n; i++)
        {
            scene->items()[i]->setEnabled(false);
        }
        scene->clear();
        mw->backGroundMusic->stop();
        mw->backGroundMusic->setMedia(QUrl("qrc:/sounds/sounds/MainTheme.mp3"));
        mw->backGroundMusic->play();
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

void GameWindow::keyReleaseEvent(QKeyEvent *event)
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

GameWindow::GameWindow(MainWindow *parent) :
    mw(parent),
    ui(new Ui::GameWindow),
    scene(new QGraphicsScene(this)),
    timer(new QTimer(this)),
    spaceship(new Spaceship(mw))
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    mw->backGroundMusic->stop();
    mw->backGroundMusic->setMedia(QUrl("qrc:/sounds/sounds/MainTheme.mp3"));
    mw->backGroundMusic->play();

    scene->setSceneRect(0, 0, width-30, height-30);

    connect(spaceship, &Spaceship::spaceshipDestroyed, this, &GameWindow::kraj);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::start()
{
    QRect rec = QApplication::primaryScreen()->geometry();
    int height = rec.height();
    int width = rec.width();

    spaceship->setStartingPosition(width/2-65, height-140);
    spaceship->setPos(spaceship->getStartingXPos(), spaceship->getStartingYPos());
    scene->addItem(spaceship);

//<<<<<<< HEAD
//    QVector<QVector<Chicken*>> chick;
//    chick.resize(8);
//    for (int i=0; i < 8; i++)
//    {
//        chick[i].resize(3);
//    }

//    for (int i=0; i < 8 ; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            chick[i][j] = new Chicken(mw,i,j);
//            scene->addItem(chick[i][j]);
//        }
//    }
//    //testiranje
//    Meteor *meteor1 = new Meteor(mw,1,1);
//    scene->addItem(meteor1);

//    Meteor *meteor2 = new Meteor(mw,2,3);
//    scene->addItem(meteor2);
//=======
    ChickenMatrixGame * cMatrixGame = new ChickenMatrixGame(mw, scene, 8,3);
    cMatrixGame->start();
//
//  MeteorShowerGame * mShowerGame = new MeteorShowerGame(mw, scene, 7, 5);
//  mShowerGame->start();

    //sideMeteorShowerGame * sideMShowerGame = new sideMeteorShowerGame(mw, scene, 7, 5);
    //sideMShowerGame->start();
//>>>>>>> maja
    // ovde pocinje igra

    //bigEgg *egg = new bigEgg(mw);
    //egg->setPos(width/2-210, pos().y() + 10);
    //scene->addItem(egg);

    // egg->throw_bullets();

    // ovde se zavrsava

    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);
}
