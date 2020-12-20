#ifndef BIGEGG_H
#define BIGEGG_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/mainwindow.h"
#include "headers/bigeggbullets.h"

class bigEgg : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    bigEgg(MainWindow* parent);
    void collision();
    QTimer* timerForEachBullet;
    QTimer* throwingTimer;
    int decrementAndGetCurrHealth();
    int getCurrHealth();

public slots:
    void move();
    void clean();
    void throw_bullets();

private:
    int width;
    int height;
    int health = 100; // promeni na 100
    bool broken = false;
    int direction = 1;
    MainWindow *mw;
};

#endif // BIGEGG_H
