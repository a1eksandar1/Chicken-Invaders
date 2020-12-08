#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>

class Spaceship : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Spaceship();
    QPointF getPosition();
    void throw_projectile();
    void move_left();
    void move_right();
    void move_up();
    void move_down();

private:
    bool alive = true;
    QTimer* throwingProjectilesTimer;
    int projectilesLevel = 5;
};

#endif // SPACESHIP_H
