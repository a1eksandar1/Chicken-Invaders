#ifndef EGG_H
#define EGG_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Egg: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Egg();
public slots:
    void move();
    void clean();


};

#endif // EGG_H
