#include "headers/projectile.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QScreen>
#include <QApplication>
#include <QMediaPlayer>
#include <QSoundEffect>

Projectile::Projectile(Spaceship* ss, QTimer* timer, int num) : number(num), spaceship(ss)
{
    setPixmap(QPixmap(":images/spaceships/projectile.png"));

//    projectileSound = new QMediaPlayer;
//    projectileSound->setMedia(QUrl("qrc:/sounds/sounds/Projectile.mp3"));
//    projectileSound->play();

    spaceship->mw->projectileSound->play();

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(10);
}

QPointF Projectile::getPosition()
{
    return pos();
}

void Projectile::move()
{
    switch (number) {
    case 1:
        //Bilo je y()-5, postavljeno je na 10 jer tako lepse radi.
        setPos(x()-0.5, y()-10);
        break;
    case 2:
        setPos(x()+0.5, y()-10);
        break;
    case 3:
        setPos(x()-1, y()-10);
        break;
    case 4:
        setPos(x()+1, y()-10);
        break;
    default: // 0
        setPos(x(), y()-10);
        if(pos().y() < 0)
            this->clean();
        if(400 < spaceship->getPosition().y()){
            if(pos().y()  > 600 - (spaceship->yStart() - spaceship->getPosition().y()))
                spaceship->setThrowingAllowed(false);
            else
                spaceship->setThrowingAllowed(true);
        }
        else{
            if(pos().y() > 10)
                spaceship->setThrowingAllowed(false);
            else
                spaceship->setThrowingAllowed(true);
        }
        if(pos().y() < -300)
            this->clean();
        if(spaceship->getPosition().y() - pos().y() < 300)
            spaceship->setThrowingAllowed(false);
        else
            spaceship->setThrowingAllowed(true);
    }
}

void Projectile::clean()
{
    scene()->removeItem(this);
    delete this;
}

