#include "headers/bigeggbullets.h"
#include "headers/spaceship.h"
#include <QScreen>
#include <QApplication>

bigEggBullets::bigEggBullets(QTimer* timer, int num) : number(num)
{
    setPixmap(QPixmap(":images/chicken/bigEggBullet2.png"));

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    height = screenGeometry.height();
    width = screenGeometry.width();

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(10);
}

void bigEggBullets::collision()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(auto colItem : colliding_items)
    {
        if(typeid (*colItem) == typeid (Spaceship))
        {
            clean();

            auto explosionSound = new QMediaPlayer;

            auto spaceship = static_cast<Spaceship*>(colItem);
            if(spaceship->decreaseLivesNumAndGetCurrNumLives() == 0)
            {
                delete colItem;
                // gameover
                explosionSound->setMedia(QUrl("qrc:/sounds/sounds/GameOver.mp3"));
                explosionSound->play();
            }
            else
            {
                spaceship->setPos(spaceship->getStartingXPos(), spaceship->getStartingYPos());
                explosionSound->setMedia(QUrl("qrc:/sounds/sounds/SpaceshipExplosion.mp3"));
                explosionSound->play();
            }

            return;
        }
    }
}

void bigEggBullets::move()
{
    switch(number){
    case 1:
        setPos(pos().x()+3, pos().y());
        if(pos().x() > width)
            this->clean();
        break;
    case 2:
        setPos(pos().x()+2, pos().y()+2);
        if(pos().x() > width || pos().y() > height)
            this->clean();
        break;
    case 3:
        setPos(pos().x(), pos().y()+3);
        if(pos().y() > height)
            this->clean();
        break;
    case 4:
        setPos(pos().x()-2, pos().y()+2);
        if(pos().x() < 0 || pos().y() > height)
            this->clean();
        break;
    case 5:
        setPos(pos().x()-3, pos().y());
        if(pos().x() < 0)
            this->clean();
        break;
    default:
        break;
    }
    collision();
}

void bigEggBullets::clean()
{
    delete this;
}
