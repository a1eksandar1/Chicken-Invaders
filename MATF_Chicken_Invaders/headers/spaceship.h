#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>
#include "headers/mainwindow.h"

class Spaceship : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Spaceship(MainWindow *parent);
    QPointF getPosition();
    void throw_projectile();
    bool getThrowingAllowed();
    void setThrowingAllowed(bool isAllowed);
    qreal yStart();
    int decreaseLivesNumAndGetCurrNumLives();
    void setStartingPosition(int pos_x, int pos_y);
    int getStartingXPos();
    int getStartingYPos();
    MainWindow *mw;
    int getProjectilesLevel() const;
    void setProjectilesLevel(int value);
    int getDirection();
    void setDirection(int d);
    void start_moving_timer();
    void stop_moving_timer();

public slots:
    void move();

private:
    bool alive = true;
    QTimer* throwingProjectilesTimer;
    QTimer* moving_timer;
    int projectilesLevel = 1;
    bool throwingAllowed = true;
    int numberOfLives = 3;
    int startingXPosition;
    int startingYPosition;
    int direction; // possible values -1, 0, 1
};

#endif // SPACESHIP_H
