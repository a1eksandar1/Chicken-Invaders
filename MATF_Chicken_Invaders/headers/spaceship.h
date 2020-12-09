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
    bool getThrowingAllowed();
    void setThrowingAllowed(bool isAllowed);
    qreal yStart();
    int decreaseLivesNumAndGetCurrNumLives();
    void setStartingPosition(int pos_x, int pos_y);
    int getStartingXPos();
    int getStartingYPos();

private:
    bool alive = true;
    QTimer* throwingProjectilesTimer;
    int projectilesLevel = 1;
    bool throwingAllowed = true;
    int numberOfLives = 3;
    int startingXPosition;
    int startingYPosition;
};

#endif // SPACESHIP_H
