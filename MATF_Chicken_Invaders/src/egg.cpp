#include "headers/egg.h"
#include "headers/spaceship.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QScreen>
#include <QApplication>
#include <QSoundEffect>

Egg::Egg(MainWindow *parent) :
    mw(parent)
{
    setPixmap(QPixmap(":images/chicken/egg_1.png").scaled(50,50,Qt::KeepAspectRatio));

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

void Egg::move()
{
    if(!mw->getFreezeScene()){
        if(!broken)
            setPos(x(), y()+10);
        if(pos().y() > height - 100)
        {
            if(!broken)
            {
                mw->eggSound->play();
                broken = true;
            }
            setPixmap(QPixmap(":images/chicken/egg_2.png").scaled(80,80,Qt::KeepAspectRatio));
            QTimer *cleanTimer = new QTimer(this);
            connect(cleanTimer, SIGNAL(timeout()), this, SLOT(clean()));
            cleanTimer->start(1000);
        }
    }
}

void Egg::clean()
{
    scene()->removeItem(this);
    delete this;
}
