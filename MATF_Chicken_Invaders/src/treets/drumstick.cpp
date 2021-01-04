#include "headers/treets_h/drumstick.h"
#include "headers/spaceship_h/spaceship.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QScreen>
#include <QApplication>
#include <QSoundEffect>

Drumstick::Drumstick(MainWindow *parent) :
    mw(parent)
{
    setPixmap(QPixmap(":images/chicken/drumstick.png").scaled(70,70,Qt::KeepAspectRatio));

    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(50);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    this->width = width;
    this->height = height;

}

void Drumstick::move()
{
    if(!mw->getFreezeScene()){

        QTransform transform;
        transform = transform.rotate(angle);
        setPixmap(QPixmap(":images/chicken/drumstick.png").scaled(70,70,Qt::KeepAspectRatio).transformed(transform));
        if(!stop)
        {
           angle += 20;
        }


        int random = rand()%2;
        if (random == 1)
            random = 1;
        else random = -1;

        if(pos().y() > height - 110)
        {
            setStop(true);
            QTimer *cleanTimer = new QTimer(this);
            connect(cleanTimer, SIGNAL(timeout()), this, SLOT(clean()));
            cleanTimer->start(1000);
        }
        else
            setPos(x()+10*random, y()+20);
    }
}

void Drumstick::clean()
{
    scene()->removeItem(this);
    delete this;
}

bool Drumstick::getStop() const
{
    return stop;
}

void Drumstick::setStop(bool value)
{
    stop = value;
}
