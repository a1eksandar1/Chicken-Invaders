#include "headers/egg.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Egg::Egg()
{
    setPixmap(QPixmap(":images/chicken/egg_1.png").scaled(50,50,Qt::KeepAspectRatio));

    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(50);

}

void Egg::move()
{
    setPos(x(), y()+10);
    if(pos().y() > 700)
    {
        setPixmap(QPixmap(":images/chicken/egg_2.png").scaled(50,50,Qt::KeepAspectRatio));
        QTimer *cleanTimer = new QTimer(this);
        connect(cleanTimer, SIGNAL(timeout()), this, SLOT(clean()));
        cleanTimer->start(1000);

    }


}

void Egg::clean()
{
    scene()->removeItem(this);
    delete this;

}
