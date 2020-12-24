#include "headers/meteor.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QDebug>
#include <QScreen>
#include <QApplication>
#include <math.h>

Meteor::Meteor(MainWindow *parent, int m, int n, int v)
    : mw(parent)
{

    this->m = m;
    this->n = n;

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    this->width = width;
    this->height = height;

    int random1= rand() % 3;
    int random2 = rand() % 5;

    this->random1 = random1;
    this->random2 = random2;

    this->x = (random1 + 1)*(width/35);


    setPixmap(QPixmap(":images/meteor/meteor1.png").scaled(x,x,Qt::KeepAspectRatio));

    if(v == 1)
    {
       setPos(200*(m+1) + random2*5, -200*(n+1) + random2*5);
    }
    else if (v == 2)
    {
        setPos(-200*(n+1) + random2*25, -200*(m+1) + random2*20);
    }
    QTimer *moveTimer = new QTimer(this);
    if(v==1)
    {
        connect(moveTimer, SIGNAL(timeout()), this, SLOT(move1()));
        moveTimer->start(80);
    }
    if (v == 2)
    {
        connect(moveTimer, SIGNAL(timeout()), this, SLOT(move2()));
        moveTimer->start(80);
    }



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
   if(!shot)
   {
        shot = true;
        emit meteorShot();
        setPixmap(QPixmap(":images/meteor/meteorShot.png").scaled(120,120,Qt::KeepAspectRatio));
        imgChange=3;
        QTimer *cleanTimer = new QTimer(this);
        connect(cleanTimer, SIGNAL(timeout()), this, SLOT(clean()));
        cleanTimer->start(200);
    }

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

void Meteor::move1()
{
    if(imgChange == 0)
        setPixmap(QPixmap(":images/meteor/meteor1.png").scaled(x,x,Qt::KeepAspectRatio));
    if(imgChange == 1)
        setPixmap(QPixmap(":images/meteor/meteor2.png").scaled(x,x,Qt::KeepAspectRatio));
    if(imgChange == 3)
        return;
    imgChange = (imgChange + 1)%2;

    setPos(pos().x(),pos().y()+speed);
    if(pos().y() > height)
    {
        die();
    }
    else if(pos().x() > width)
    {
        die();
    }

}

void Meteor::move2()
{
    if(imgChange == 0)
        setPixmap(QPixmap(":images/meteor/meteor3.png").scaled(x,x,Qt::KeepAspectRatio));
    if(imgChange == 1)
        setPixmap(QPixmap(":images/meteor/meteor4.png").scaled(x,x,Qt::KeepAspectRatio));
    if(imgChange == 3)
        return;
    imgChange = (imgChange + 1)%2;

    setPos(pos().x()+speed,pos().y()+speed);
}


void Meteor::advance(int step)
{
    if (!step)
    {
        return;
    }


}
