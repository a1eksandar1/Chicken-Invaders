#ifndef EGG_H
#define EGG_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
class Egg: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Egg();

public slots:
    void move();
    void clean();

private:
    int width, height;
    QMediaPlayer * eggSound;
    bool broken = false;

};

#endif // EGG_H
