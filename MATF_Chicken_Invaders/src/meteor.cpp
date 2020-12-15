#include "headers/meteor.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QDebug>
#include <QScreen>
#include <QApplication>

Meteor::Meteor(MainWindow *parent, int m, int n)
    : mw(parent)
{

    this->m = m;
    this->n = n;

    int random1= rand() % 3;
    int random2 = rand() % 5;

    this->x = (random1 + 1)*30;

    setPixmap(QPixmap(":images/meteor/meteor1.png").scaled(x,x,Qt::KeepAspectRatio));

    setPos(150*(m+random1) + 50*(random2), -150*(n+random2) + 30*random1);

    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(80);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    this->width = width;
    this->height = height;


}

Meteor::~Meteor()
{

}


bool Meteor::getShot() const
{
    return shot;
}

void Meteor::setShot(bool value)
{
    shot = value;
}

void Meteor::die()
{
//TODO
    scene()->removeItem(this);
    delete this;
}

void Meteor::clean()
{
    scene()->removeItem(this);
    delete this;
}

int Meteor::getImgChange() const
{
    return imgChange;
}

void Meteor::setImgChange(int value)
{
   imgChange = value;
}

void Meteor::move()
{
    if(imgChange == 0)
        setPixmap(QPixmap(":images/meteor/meteor1.png").scaled(x,x,Qt::KeepAspectRatio));
    if(imgChange == 1)
        setPixmap(QPixmap(":images/meteor/meteor2.png").scaled(x,x,Qt::KeepAspectRatio));
    if(imgChange == 3)
        return;
    imgChange = (imgChange + 1)%2;


    setPos(pos().x(),pos().y()+speed);;


}


void Meteor::advance(int step)
{
    if (!step)
    {
        return;
    }


}
