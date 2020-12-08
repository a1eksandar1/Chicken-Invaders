#include "headers/planet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QDebug>
#include <QScreen>
#include <QApplication>

void Planet::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(name == "Pluto"){
        mw->setDesiredLevel(1);
        emit plutoClicked();
    }
    else if(name == "Neptune"){
        if(mw->getReachedLevel() > 1){
            mw->setDesiredLevel(2);
            emit neptuneClicked();
        }
    }
    else if(name == "Uranus"){
        if(mw->getReachedLevel() > 2){
        mw->setDesiredLevel(3);
        emit uranusClicked();
        }
    }
    else if(name == "Saturn"){
        if(mw->getReachedLevel() > 3){
            mw->setDesiredLevel(4);
            emit saturnClicked();
        }
    }
    else if(name == "Jupiter"){
        if(mw->getReachedLevel() > 4){
            mw->setDesiredLevel(5);
            emit jupiterClicked();
        }
    }
    else if(name == "Mars"){
        if(mw->getReachedLevel() > 5){
            mw->setDesiredLevel(6);
            emit marsClicked();
        }
    }
    else if(name == "Earth"){
        if(mw->getReachedLevel() > 6){
            mw->setDesiredLevel(7);
            emit earthClicked();
        }
    }
    else if(name == "Venus"){
        if(mw->getReachedLevel() > 7){
            mw->setDesiredLevel(8);
            emit venusClicked();
        }
    }
    else if(name == "Mercury"){
        if(mw->getReachedLevel() > 8){
            mw->setDesiredLevel(9);
            emit mercuryClicked();
        }
    }
    update();
}

Planet::Planet(MainWindow *parent, qreal pos_x, qreal pos_y, qreal height, qreal width, QString name):
    pos_x(pos_x),
    pos_y(pos_y),
    height(height),
    width(width),
    mw(parent),
    name(name)
{

}

QRectF Planet::boundingRect() const
{
    return QRectF(pos_x, pos_y, height, width);
}

void Planet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Ne pomaze
    //QPen bp(Qt::black);
    //bp.setWidth(0);
    //painter->setPen(bp);
    painter->drawEllipse(pos_x, pos_y, height, width);
}
