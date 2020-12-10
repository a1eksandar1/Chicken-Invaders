#include "headers/planet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QScreen>
#include <QApplication>

void Planet::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    (void)event;

    if(mw->getPlanetClicked() == false){
        if(name == "Pluto"){
            mw->setDesiredLevel(1);
            mw->setPlanetClicked(true);
            emit plutoClicked();
        }
        else if(name == "Neptune"){
            if(mw->getReachedLevel() > 1){
                mw->setDesiredLevel(2);
                mw->setPlanetClicked(true);
                emit neptuneClicked();
            }
        }
        else if(name == "Uranus"){
            if(mw->getReachedLevel() > 2){
            mw->setDesiredLevel(3);
            mw->setPlanetClicked(true);
            emit uranusClicked();
            }
        }
        else if(name == "Saturn"){
            if(mw->getReachedLevel() > 3){
                mw->setDesiredLevel(4);
                mw->setPlanetClicked(true);
                emit saturnClicked();
            }
        }
        else if(name == "Jupiter"){
            if(mw->getReachedLevel() > 4){
                mw->setDesiredLevel(5);
                mw->setPlanetClicked(true);
                emit jupiterClicked();
            }
        }
        else if(name == "Mars"){
            if(mw->getReachedLevel() > 5){
                mw->setDesiredLevel(6);
                mw->setPlanetClicked(true);
                emit marsClicked();
            }
        }
        else if(name == "Earth"){
            if(mw->getReachedLevel() > 6){
                mw->setDesiredLevel(7);
                mw->setPlanetClicked(true);
                emit earthClicked();
            }
        }
        else if(name == "Venus"){
            if(mw->getReachedLevel() > 7){
                mw->setDesiredLevel(8);
                mw->setPlanetClicked(true);
                emit venusClicked();
            }
        }
        else if(name == "Mercury"){
            if(mw->getReachedLevel() > 8){
                mw->setDesiredLevel(9);
                mw->setPlanetClicked(true);
                emit mercuryClicked();
            }
        }
        update();
    }
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
    (void)option;
    (void)widget;

    QPen tp(Qt::transparent);
    painter->setPen(tp);
    painter->drawEllipse(pos_x, pos_y, height, width);
}
