#include "headers/spaceship.h"
#include "headers/projectile.h"
#include <QTimer>

Spaceship::Spaceship()
{
    setPixmap(QPixmap(":images/spaceships/1.png"));
}

QPointF Spaceship::getPosition()
{
    return pos();
}

void Spaceship::throw_projectile()
{
    Projectile* projectile = new Projectile();
    projectile->setPos(pos().x()+40, pos().y()-20);
    scene()->addItem(projectile);
}

void Spaceship::move_left()
{
    setPos(pos().x()-10, pos().y());
}

void Spaceship::move_right()
{
    setPos(pos().x()+10, pos().y());
}

void Spaceship::move_up()
{
    setPos(pos().x(), pos().y()-10);
}

void Spaceship::move_down()
{
    setPos(pos().x(), pos().y()+10);
}
