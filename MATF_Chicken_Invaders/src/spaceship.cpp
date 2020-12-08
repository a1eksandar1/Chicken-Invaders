#include "headers/spaceship.h"
#include "headers/projectile.h"
#include <QTimer>
#include <vector>

Spaceship::Spaceship()
{
    setPixmap(QPixmap(":images/spaceships/1.png"));
    throwingProjectilesTimer = new QTimer();
}

QPointF Spaceship::getPosition()
{
    return pos();
}

void Spaceship::throw_projectile()
{
    std::vector<Projectile*> projectiles;
    for(int i=0; i<projectilesLevel; i++){ // alociranje projektila
        if(projectilesLevel == 1 || projectilesLevel == 2)
            projectiles.push_back(new Projectile(throwingProjectilesTimer, 0));
        else if(projectilesLevel == 3 || projectilesLevel == 5)
            projectiles.push_back(new Projectile(throwingProjectilesTimer, i));
        else
            projectiles.push_back(new Projectile(throwingProjectilesTimer, i+1));
    }

    switch (projectilesLevel) { // postavljanje pozicije projektila
    case 2:
        projectiles[0]->setPos(pos().x()+15, pos().y()-40);
        projectiles[1]->setPos(pos().x()+45, pos().y()-40);
        break;
    case 3:
        projectiles[0]->setPos(pos().x()+30, pos().y()-40);
        projectiles[1]->setPos(pos().x()+10, pos().y()-25);
        projectiles[2]->setPos(pos().x()+50, pos().y()-25);
        break;
    case 4:
        projectiles[2]->setPos(pos().x()-10, pos().y()-25);
        projectiles[1]->setPos(pos().x()+45, pos().y()-40);
        projectiles[0]->setPos(pos().x()+15, pos().y()-40);
        projectiles[3]->setPos(pos().x()+70, pos().y()-25);
        break;
    case 5:
        projectiles[0]->setPos(pos().x()+30, pos().y()-40);
        projectiles[3]->setPos(pos().x()-10, pos().y()-10);
        projectiles[2]->setPos(pos().x()+50, pos().y()-25);
        projectiles[1]->setPos(pos().x()+10, pos().y()-25);
        projectiles[4]->setPos(pos().x()+70, pos().y()-10);
        break;
    default: // 1
        projectiles[0]->setPos(pos().x()+30, pos().y()-40);
    }

    for(auto projectile : projectiles)
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
