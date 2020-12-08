#include "headers/chicken.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "headers/egg.h"
#include "headers/gift.h"
#include <stdlib.h>
#include <QDebug>
#include <QScreen>
#include <QApplication>

Chicken::Chicken(MainWindow *parent, int m, int n)
    : mw(parent)
{

    chicken_sound = new QMediaPlayer;
    chicken_sound->setMedia(QUrl("qrc:/sounds/sounds/shot_chicken.mp3"));
    chicken_sound->setVolume(parent->getVolume());

    this->m = m;
    this->n = n;
    setPixmap(QPixmap(":images/chicken/matf_chicken1.png").scaled(120,120,Qt::KeepAspectRatio));

    setPos(150*m + 20, 120*n + 10);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    this->width = width;
    this->height = height;


}

Chicken::~Chicken()
{

}



int Chicken::getOrientation() const
{
    return orientation;
}

void Chicken::setOrientation(int value)
{
    orientation = value;
}

bool Chicken::getShot() const
{
    return shot;
}

void Chicken::setShot(bool value)
{
    shot = value;
}

void Chicken::clean()
{
    scene()->removeItem(this);
    delete this;
}

int Chicken::getImgChange() const
{
    return imgChange;
}

void Chicken::setImgChange(int value)
{
    imgChange = value;
}

void Chicken::advance(int step)
{
    if (!step)
    {
        return;
    }

    if(imgChange == 0)
        setPixmap(QPixmap(":images/chicken/matf_chicken1.png").scaled(120,120,Qt::KeepAspectRatio));
    if(imgChange == 1)
        setPixmap(QPixmap(":images/chicken/matf_chicken2.png").scaled(120,120,Qt::KeepAspectRatio));

    imgChange = (imgChange + 1)%2;

    int random_number = rand() % 700;
    if (random_number == 5)
    {
        Egg * egg = new Egg(mw);
        egg->setPos(pos().x(),pos().y()+100);
        scene()->addItem(egg);

        setShot(true); //for testing

    }

    if (random_number == 7)
    {
        Gift * gift = new Gift(mw);
        gift->setPos(pos().x(),pos().y()+100);
        scene()->addItem(gift);

    }

    if(getShot())
    {
        setPixmap(QPixmap(":images/chicken/shot_chicken.png").scaled(120,120,Qt::KeepAspectRatio));
        chicken_sound->play();
        QTimer *cleanTimer = new QTimer(this);
        connect(cleanTimer, SIGNAL(timeout()), this, SLOT(clean()));
        cleanTimer->start(500);
    }
    if(pos().x() + 150*(7-m) > width - 150)
        orientation = -10;

    if(pos().x() - 150*(m) < 0)
        orientation = 10;

    setPos(pos().x()+orientation,pos().y());

}
