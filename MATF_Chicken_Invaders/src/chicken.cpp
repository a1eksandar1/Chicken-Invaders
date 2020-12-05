#include "headers/chicken.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "headers/egg.h"
#include <stdlib.h>
#include <QDebug>
#include <QScreen>
#include <QApplication>

Chicken::Chicken(int m, int n)
{
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
        Egg * egg = new Egg();
        egg->setPos(pos().x(),pos().y()+100);
        scene()->addItem(egg);
    }

    if(pos().x() + 150*(7-m) > width - 150)
        orientation = -10;

    if(pos().x() - 150*(m) < 0)
        orientation = 10;

    setPos(pos().x()+orientation,pos().y());



}
