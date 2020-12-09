#include "headers/spaceship.h"
#include "headers/projectile.h"
#include <QTimer>
#include <vector>
#include <QApplication>
#include <QScreen>

Spaceship::Spaceship(MainWindow *parent) :
    mw(parent)
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
            projectiles.push_back(new Projectile(this, throwingProjectilesTimer, 0));
        else if(projectilesLevel == 3 || projectilesLevel == 5)
            projectiles.push_back(new Projectile(this, throwingProjectilesTimer, i));
        else
            projectiles.push_back(new Projectile(this, throwingProjectilesTimer, i+1));
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

//Malo sam ubrzao kretane svemirskog broda.
void Spaceship::move_left()
{
    if(pos().x() > 20)
        setPos(pos().x()-30, pos().y());
}

void Spaceship::move_right()
{
    if(pos().x() < 2*getStartingXPos()-20)
        setPos(pos().x()+30, pos().y());
}

void Spaceship::move_up()
{
    if(pos().y() > 20)
        setPos(pos().x(), pos().y()-30);
}

void Spaceship::move_down()
{
    if(pos().y() < getStartingYPos()-20)
        setPos(pos().x(), pos().y()+30);

}

bool Spaceship::getThrowingAllowed()
{
    return throwingAllowed;
}

void Spaceship::setThrowingAllowed(bool isAllowed)
{
    throwingAllowed = isAllowed;
}

qreal Spaceship::yStart()
{
    QRect rec = QApplication::primaryScreen()->geometry();
    int width = rec.width();

    return width/2;
}

int Spaceship::decreaseLivesNumAndGetCurrNumLives(){
    return --numberOfLives;
}

void Spaceship::setStartingPosition(int pos_x, int pos_y)
{
    startingXPosition = pos_x;
    startingYPosition = pos_y;
}

int Spaceship::getStartingXPos()
{
    return startingXPosition;
}

int Spaceship::getStartingYPos()
{
    return startingYPosition;
}

int Spaceship::getProjectilesLevel() const
{
    return projectilesLevel;
}

void Spaceship::setProjectilesLevel(int value)
{
    projectilesLevel = value;
}
