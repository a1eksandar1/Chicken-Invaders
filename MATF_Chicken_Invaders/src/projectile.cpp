#include "headers/projectile.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QScreen>
#include <QApplication>
#include <QMediaPlayer>
#include <QSoundEffect>

Projectile::Projectile()
{
    setPixmap(QPixmap(":images/spaceships/projectile.png").scaled(20,20,Qt::KeepAspectRatio));

    projectileSound = new QMediaPlayer;
    projectileSound->setMedia(QUrl("qrc:/sounds/sounds/Projectile.mp3"));
    projectileSound->play();

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(10);
}

QPointF Projectile::getPosition()
{
    return pos();
}

void Projectile::move()
{
    setPos(x(), y()-5);

    // if pos > ..
}

void Projectile::clean()
{
    scene()->removeItem(this);
    delete this;
}

