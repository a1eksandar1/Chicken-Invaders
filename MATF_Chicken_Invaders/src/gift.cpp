#include "headers/gift.h"
#include "headers/egg.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QScreen>
#include <QApplication>
#include <QMediaPlayer>
#include <QSoundEffect>

Gift::Gift(MainWindow *parent)
{
    setPixmap(QPixmap(":images/chicken/gift_1.png").scaled(60,60,Qt::KeepAspectRatio));

    giftSound = new QMediaPlayer;
    giftSound->setMedia(QUrl("qrc:/sounds/sounds/GiftSound.mp3"));
    giftSound->setVolume(parent->getVolume());
    giftSound->play();

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

void Gift::move()
{
    setPos(x(), y()+10);
    if(pos().y() > height)
    {
        clean();
    }

    colision();
}

void Gift::clean()
{
    scene()->removeItem(this);
    delete this;

}

void Gift::colision()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(auto colItem : colliding_items)
    {
        if(typeid (*colItem) == typeid(Spaceship))
        {
            auto spaceship = static_cast<Spaceship*>(colItem);
            int level = spaceship->getProjectilesLevel();
            if(level < 5)
                spaceship->setProjectilesLevel(level+1);

            giftSound->play();

            clean();
        }
    }
}
