#include "headers/projectile.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QScreen>
#include <QApplication>

Projectile::Projectile(Spaceship* ss, QTimer* timer, int num) : number(num), spaceship(ss)
{
    setPixmap(QPixmap(":images/spaceships/projectile.png"));

    spaceship->mw->projectileSound->stop();
    spaceship->mw->projectileSound->play();
    spaceship->mw->projectileSound->setVolume(spaceship->mw->getVolume());

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(10);
}

QPointF Projectile::getPosition()
{
    return pos();
}

void Projectile::move()
{
    if(!(spaceship->mw->getFreezeScene())){
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
            /*
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
            */
            if(pos().y() < -300)
                this->clean();
            if(spaceship->getPosition().y() - pos().y() < 300)
                spaceship->setThrowingAllowed(false);
            else
                spaceship->setThrowingAllowed(true);

        }
        colision();
    }
}

void Projectile::colision()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(auto colItem : colliding_items)
    {
        if(typeid (*colItem) == typeid (Chicken))
        {
            auto chicken = static_cast<Chicken*>(colItem);
            chicken->die();
            spaceship->setThrowingAllowed(true);
            clean();
        }
        else if(typeid (*colItem) == typeid (Meteor))
        {
            auto meteor = static_cast<Meteor*>(colItem);
            meteor->die();
            spaceship->setThrowingAllowed(true);
            clean();
        }
    }
}

void Projectile::clean()
{
    scene()->removeItem(this);
    delete this;
}

