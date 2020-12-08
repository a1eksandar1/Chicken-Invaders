#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QTimer>
#include "headers/spaceship.h"

class Projectile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Projectile(Spaceship* ss, QTimer* timer, int num);
    QPointF getPosition();

public slots:
    void move();
    void clean();

private:
    bool exploded = false;
    QMediaPlayer* projectileSound;
    int number;
    Spaceship* spaceship;
};

#endif // PROJECTILE_H
