#include "headers/egg.h"
#include "headers/spaceship.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QScreen>
#include <QApplication>
#include <QMediaPlayer>
#include <QSoundEffect>

Egg::Egg(MainWindow *parent)
{
    setPixmap(QPixmap(":images/chicken/egg_1.png").scaled(50,50,Qt::KeepAspectRatio));

    eggSound = new QMediaPlayer;
    eggSound->setMedia(QUrl("qrc:/sounds/sounds/Egg.mp3"));
    eggSound->setVolume(parent->getVolume());

    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(50);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    this->width = width;
    this->height = height;

}

void Egg::move()
{
    setPos(x(), y()+10);
    if(pos().y() > height - 150)
    {
        if(!broken)
        {
            eggSound->play();
            broken = true;
        }
        setPixmap(QPixmap(":images/chicken/egg_2.png").scaled(50,50,Qt::KeepAspectRatio));
        QTimer *cleanTimer = new QTimer(this);
        connect(cleanTimer, SIGNAL(timeout()), this, SLOT(clean()));
        cleanTimer->start(1000);
    }

    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(auto colItem : colliding_items){
        if(typeid (*colItem) == typeid (Spaceship)){

            scene()->removeItem(this);
            delete this;

            auto explosionSound = new QMediaPlayer;

            auto spaceship = static_cast<Spaceship*>(colItem);
            if(spaceship->decreaseLivesNumAndGetCurrNumLives() == 0){
                delete colItem;
                // gameover
                explosionSound->setMedia(QUrl("qrc:/sounds/sounds/GameOver.mp3"));
                explosionSound->play();
            }
            else{
                spaceship->setPos(spaceship->getStartingXPos(), spaceship->getStartingYPos());
                explosionSound->setMedia(QUrl("qrc:/sounds/sounds/SpaceshipExplosion.mp3"));
                explosionSound->play();
            }

            return;
        }
    }
}

void Egg::clean()
{
    scene()->removeItem(this);
    delete this;

}
