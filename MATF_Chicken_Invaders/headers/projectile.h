#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QTimer>

class Projectile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Projectile(QTimer* timer, int num);
    QPointF getPosition();

public slots:
    void move();
    void clean();

private:
    bool exploded = false;
    QMediaPlayer* projectileSound;
    int number;
};

#endif // PROJECTILE_H
