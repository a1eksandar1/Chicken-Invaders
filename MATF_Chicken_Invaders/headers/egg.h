#ifndef EGG_H
#define EGG_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/mainwindow.h"

class Egg: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Egg(MainWindow *parent);

    void colision();

public slots:
    void move();
    void clean();

private:
    int width, height;
    bool broken = false;
    MainWindow *mw;
};

#endif // EGG_H
