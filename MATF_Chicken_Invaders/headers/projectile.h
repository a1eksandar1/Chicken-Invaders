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
    Projectile(QTimer* timer);
    QPointF getPosition();

public slots:
    void move();
    void clean();

private:
    bool exploded = false;
    QMediaPlayer* projectileSound;
};

#endif // PROJECTILE_H
