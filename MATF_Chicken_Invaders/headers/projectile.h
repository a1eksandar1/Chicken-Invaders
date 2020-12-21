#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "headers/spaceship.h"
#include "headers/chicken.h"
#include "headers/meteor.h"
#include "headers/bigchicken.h"
#include "headers/drumstick.h"

class Projectile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Projectile(Spaceship* ss, QTimer* timer, int num);
    QPointF getPosition();

    void colision();
public slots:
    void move();
    void clean();

private:
    bool exploded = false;
    int number;
    Spaceship* spaceship;
};

#endif // PROJECTILE_H
