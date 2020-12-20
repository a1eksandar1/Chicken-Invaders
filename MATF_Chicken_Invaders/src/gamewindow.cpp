#include "headers/gamewindow.h"
#include "headers/chicken.h"
#include "headers/egg.h"
#include "headers/projectile.h"
#include "headers/bigegg.h"
#include "headers/bigeggbullets.h"
#include "ui_gamewindow.h"
#include <QDialog>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QScreen>
#include <QTimer>

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape){
        for(size_t i=0, n = scene->items().size(); i<n; i++)
        {
            scene->items()[i]->setEnabled(false);
        }
        scene->clear();
        mw->backGroundMusic->stop();
        mw->backGroundMusic->setMedia(QUrl("qrc:/sounds/sounds/MainTheme2.mp3"));
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
    mw->backGroundMusic->setMedia(QUrl("qrc:/sounds/sounds/MainTheme1.mp3"));
    mw->backGroundMusic->play();

    scene->setSceneRect(0, 0, width-30, height-30);
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

    // ovde pocinje igra

    bigEgg *egg = new bigEgg(mw);
    egg->setPos(width/2-210, pos().y() + 10);
    scene->addItem(egg);

    // egg->throw_bullets();

    // ovde se zavrsava

    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);

}
