#include "headers/sidespaceship.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QScreen>
#include <QApplication>
#include "headers/gamewindow.h"

SideSpaceship::SideSpaceship(MainWindow *parent)
    : move(5),
      mw(parent),
      boundary(std::numeric_limits<qreal>::max()),
      moving(true)

{
    setPixmap(QPixmap(":images/spaceships/spaceship_on_the_side.png").scaled(120,120,Qt::KeepAspectRatio));

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    setPos(-100, height-height/3.5);

    this->width = width;
    this->height = height;

}

SideSpaceship::~SideSpaceship()
{

}

qreal SideSpaceship::getBoundary() const
{
    return boundary;
}

void SideSpaceship::setBoundary(const qreal &value)
{
    boundary = value;
}

int SideSpaceship::getMove() const
{
    return move;
}

void SideSpaceship::setMove(int value)
{
    move = value;
}

void SideSpaceship::advance(int step)
{
    if(!step || !moving)
        return;

    if(pos().x() >= boundary){
        move = 0;
        emit sidespaceshipStop();
        moving = false;
    }

    setPos(pos().x()+move,pos().y());
}
