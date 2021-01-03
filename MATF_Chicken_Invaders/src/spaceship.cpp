#include "headers/spaceship.h"
#include "headers/projectile.h"
#include "headers/drumstick.h"
#include "headers/bigchicken.h"
#include "headers/bigeggbullets.h"
#include "headers/gift.h"
#include <QTimer>
#include <vector>
#include <QApplication>
#include <QScreen>

Spaceship::Spaceship(MainWindow *parent) :
    mw(parent)
{
    if(!mw->isHard())
        setPixmap(QPixmap(":images/spaceships/1.png"));
    else
        setPixmap(QPixmap(":images/spaceships/4.png"));
    throwingProjectilesTimer = new QTimer();
    destroyedTimer = new QTimer();
    connect(destroyedTimer, SIGNAL(timeout()), this, SLOT(enableSpaceshipAfterDestroying()));
    moving_timer = new QTimer();
    moving_timer->setInterval(10);
    connect(moving_timer, SIGNAL(timeout()), this, SLOT(move()));
    projectilesLevel = mw->getProjectilesLevel();
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
        else{
            if(i == 0 || i == 1)
                projectiles.push_back(new Projectile(this, throwingProjectilesTimer, 0));
            else
                projectiles.push_back(new Projectile(this, throwingProjectilesTimer, i+1));
        }
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

/*void Spaceship::move_left()
{
    if(pos().x() > 20)
        setPos(pos().x()-5, pos().y());
}

void Spaceship::move_right()
{
    if(pos().x() < 2*getStartingXPos()-20)
        setPos(pos().x()+5, pos().y());
}*/

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
    startingYPosition = pos_y - 50;
}

int Spaceship::getStartingXPos()
{
    return startingXPosition;
}

int Spaceship::getStartingYPos()
{
    return startingYPosition;
}

void Spaceship::collision()
{

    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(auto colItem : colliding_items)
    {
        if(typeid (*colItem) == typeid (Meteor))
        {
            auto meteor = static_cast<Meteor*>(colItem);
            meteor->die();

            this->checkIfSpaceshipDestroyed();

            return;
        }
        else if(typeid (*colItem) == typeid (Egg))
        {
            auto egg = static_cast<Egg*>(colItem);
            egg->clean();

            this->checkIfSpaceshipDestroyed();

            return;
        }
        else if(typeid (*colItem) == typeid (Drumstick))
        {
            auto drumstick = static_cast<Drumstick*>(colItem);
            drumstick->clean();


// increase score
//            for(int i=0; i<10;i++)
//                mw->getScore()->increaseScore();
            emit changeScore(10);

            return;
        }
        else if(typeid (*colItem) == typeid (RoastChicken))
        {
            auto roastC = static_cast<RoastChicken*>(colItem);
            roastC->clean();
      //TODO: points
//            for(int i=0; i<50;i++)
//                mw->getScore()->increaseScore();
            emit changeScore(50);

            return;
        }
        else if(typeid (*colItem) == typeid (EggChicken))
        {
            auto ec = static_cast<EggChicken*>(colItem);
            ec->die();

            this->checkIfSpaceshipDestroyed();

            return;
        }
        else if(typeid (*colItem) == typeid (BigChicken))
        {
            auto bc = static_cast<BigChicken*>(colItem);
            bc->setPos((bc->getWidth()-2)/2-250, 0);

            this->checkIfSpaceshipDestroyed();

            return;
        }
        else if(typeid (*colItem) == typeid (bigEggBullets))
        {
            auto bigEggBullet = static_cast<bigEggBullets*>(colItem);
            bigEggBullet->clean();
            // clean();

            this->checkIfSpaceshipDestroyed();

            return;
        }
        else if(typeid (*colItem) == typeid(Gift))
        {
            auto gift = static_cast<Gift*>(colItem);
            int level = this->getProjectilesLevel();
            if(level < 5)
                this->setProjectilesLevel(level+1);

            mw->giftSound->play();

            gift->clean();
        }
    }

}

void Spaceship::checkIfSpaceshipDestroyed()
{
    this->revertProjectilesLevel();

    if(decreaseLivesNumAndGetCurrNumLives() == 0)
    {
        mw->explosionSound->setMedia(QUrl("qrc:/sounds/sounds/GameOver.mp3"));
        mw->explosionSound->play();
        emit spaceshipDestroyed();
        delete this;
    }
    else
    {
        setPos(getStartingXPos(), getStartingYPos());
        mw->explosionSound->setMedia(QUrl("qrc:/sounds/sounds/SpaceshipExplosion.mp3"));
        mw->explosionSound->play();

        setInvisible();
    }
}

void Spaceship::setInvisible()
{
    isCurrentlyDestroyed = true;
    setPixmap(QPixmap(":images/spaceships/1_cd.png"));
    destroyedTimer->start(3000);
}

int Spaceship::getProjectilesLevel() const
{
    return projectilesLevel;
}

void Spaceship::setProjectilesLevel(int value)
{
    projectilesLevel = value;
}

void Spaceship::advance(int step)
{
    if(!step)
        return;

    if(!isCurrentlyDestroyed)
        collision();
}

int Spaceship::getDirection()
{
    return direction;
}

void Spaceship::setDirection(int d)
{
    direction = d;
}

void Spaceship::move()
{
    if((direction == -1 && pos().x() <= 20) || (direction == 1 && pos().x() >= 2*getStartingXPos()-20)){
        direction = 0;
        return;
    }

    setPos(pos().x()+5*direction, pos().y());
}

void Spaceship::enableSpaceshipAfterDestroying()
{
    setPixmap(QPixmap(":images/spaceships/1.png"));
    destroyedTimer->stop();
    isCurrentlyDestroyed = false;
}

void Spaceship::start_moving_timer()
{
    moving_timer->start();
}

void Spaceship::stop_moving_timer()
{
    moving_timer->stop();
}

void Spaceship::revertProjectilesLevel()
{
    projectilesLevel = 1;
}
