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

    auto x = 0.75*m*60;
    auto y = 0.75*m*60;

    setPixmap(QPixmap(":images/meteor/meteor1.png").scaled(x,y,Qt::KeepAspectRatio));

    setPos(150*m, 120*n);

    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(100);

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



int Meteor::getOrientation() const
{
    return orientation;
}

void Meteor::setOrientation(int value)
{
    orientation = value;
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
    auto x = 0.75*m*60;
    auto y = 0.75*m*60;

    if(imgChange == 0)
        setPixmap(QPixmap(":images/meteor/meteor1.png").scaled(x,y,Qt::KeepAspectRatio));
    if(imgChange == 1)
        setPixmap(QPixmap(":images/meteor/meteor2.png").scaled(x,y,Qt::KeepAspectRatio));
    if(imgChange == 3)
        return;
    imgChange = (imgChange + 1)%2;


    setPos(pos().x(),pos().y()+orientation);;

}

void Meteor::advance(int step)
{
    if (!step)
    {
        return;
    }


}
