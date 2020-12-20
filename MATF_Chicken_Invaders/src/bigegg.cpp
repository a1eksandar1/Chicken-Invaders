#include "headers/bigegg.h"
#include "headers/projectile.h"
#include <QApplication>
#include <QGraphicsItem>
#include <QList>
#include <QScreen>
#include <QSoundEffect>
#include <QGraphicsScene>

bigEgg::bigEgg(MainWindow *parent) : mw(parent)
{
    setPixmap(QPixmap(":images/chicken/bigEgg.png").scaled(500,500,Qt::KeepAspectRatio));

    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(50);

    timerForEachBullet = new QTimer;

    throwingTimer = new QTimer;
    connect(throwingTimer, SIGNAL(timeout()), this, SLOT(throw_bullets()));
    throwingTimer->start(2500);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    this->width = width;
    this->height = height;
}

void bigEgg::collision()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(auto colItem : colliding_items)
    {
        if(typeid (*colItem) == typeid (Projectile))
        {
            delete colItem;

            if(getCurrHealth() == 75)
                setPixmap(QPixmap(":images/chicken/bigEgg_cl1.png").scaled(500,500,Qt::KeepAspectRatio));
            else if(getCurrHealth() == 50)
                setPixmap(QPixmap(":images/chicken/bigEgg_cl2.png").scaled(500,500,Qt::KeepAspectRatio));
            else if(getCurrHealth() == 25)
                setPixmap(QPixmap(":images/chicken/bigEgg_cl3.png").scaled(500,500,Qt::KeepAspectRatio));

            if(decrementAndGetCurrHealth() == 0)
                clean();

            return;
        }
    }
}

void bigEgg::throw_bullets()
{
    std::vector<bigEggBullets*> big_egg_bullets;
    for (int i=1; i<6; i++){
        big_egg_bullets.push_back(new bigEggBullets(timerForEachBullet, i));
    }

    big_egg_bullets[0]->setPos(pos().x()+440, pos().y()+250);
    big_egg_bullets[1]->setPos(pos().x()+385, pos().y()+430);
    big_egg_bullets[2]->setPos(pos().x()+185, pos().y()+500);
    big_egg_bullets[3]->setPos(pos().x(), pos().y()+430);
    big_egg_bullets[4]->setPos(pos().x()-50, pos().y()+250);

    for(auto bull : big_egg_bullets)
        scene()->addItem(bull);
}

void bigEgg::move()
{
    if(direction > 0){ // ide udesno
        if(pos().x() > width - 930)
            direction = -direction;
    }
    else{ // ide ulevo
        if(pos().x() < 500)
            direction = -direction;
    }

    setPos(pos().x() + 3*direction, pos().y());

    collision();
}

void bigEgg::clean()
{
    scene()->removeItem(this);
    delete this;
}

int bigEgg::decrementAndGetCurrHealth()
{
    return --health;
}

int bigEgg::getCurrHealth()
{
    return health;
}
