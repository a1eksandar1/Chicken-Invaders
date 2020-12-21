#include "headers/gift.h"
#include "headers/egg.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QScreen>
#include <QApplication>
#include <QSoundEffect>

Gift::Gift(MainWindow *parent) :
    mw(parent)
{
    setPixmap(QPixmap(":images/chicken/gift_1.png").scaled(60,60,Qt::KeepAspectRatio));

    mw->giftSound->play();

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

void Gift::move()
{
    setPos(x(), y()+10);
    if(pos().y() > height)
    {
        clean();
    }
}

void Gift::clean()
{
    scene()->removeItem(this);
    delete this;

}
