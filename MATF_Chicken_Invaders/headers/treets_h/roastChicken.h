#ifndef ROASTCHICKEN_H
#define ROASTCHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/main_h/mainwindow.h"
#include <math.h>

class RoastChicken: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    RoastChicken(MainWindow *parent);

    void colision();

    bool getStop() const;
    void setStop(bool value);

public slots:
    void move();
    void clean();

private:
    int width, height;
    bool stop = false;
    double angle = 30;
    MainWindow *mw;
};

#endif // ROASTCHICKEN_H
