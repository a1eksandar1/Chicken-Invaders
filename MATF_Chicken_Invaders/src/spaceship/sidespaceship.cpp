#include "headers/spaceship_h/sidespaceship.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QScreen>
#include <QApplication>
#include <QtMath>

SideSpaceship::SideSpaceship(MainWindow *parent) :
    move_x(5),
    move_y(3),
    mw(parent),
    boundary_x(std::numeric_limits<qreal>::max()),
    boundary_y(std::numeric_limits<qreal>::max()),
    moving(true)
{
    setPixmap(QPixmap(":images/spaceships/spaceship_on_the_side.png").scaled(120,120,Qt::KeepAspectRatio));

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    setPos(-200, 100);

    this->width = width;
    this->height = height;

}

SideSpaceship::~SideSpaceship()
{

}

qreal SideSpaceship::getBoundary_x() const
{
    return boundary_x;
}

void SideSpaceship::setBoundary_x(const qreal &value)
{
    boundary_x = value;
}

int SideSpaceship::getMove_x() const
{
    return move_x;
}

void SideSpaceship::setMove_x(int value)
{
    move_x = value;
}

qreal SideSpaceship::getBoundary_y() const
{
    return boundary_y;
}

void SideSpaceship::setBoundary_y(const qreal &value)
{
    boundary_y = value;
}

int SideSpaceship::getMove_y() const
{
    return move_y;
}

void SideSpaceship::setMove_y(int value)
{
    move_y = value;
}

void SideSpaceship::advance(int step)
{
    if(!step || !moving)
        return;

    if(pos().x() >= boundary_x)
        move_x = 0;

    if(pos().y() >= boundary_y)
        move_y = 0;

    if(pos().x() >= boundary_x && pos().y() >= boundary_y){
        emit sidespaceshipStop();
        moving = false;
    }

    setPos(pos().x()+move_x,pos().y()+move_y);
}
