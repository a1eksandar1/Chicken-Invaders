#ifndef BIGEGG_H
#define BIGEGG_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/mainwindow.h"
#include "headers/bigeggbullets.h"

class bigEgg : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

signals:
    void endOfBigEggGame();

public:
    bigEgg(MainWindow* parent);
    QTimer* timerForEachBullet;
    QTimer* throwingTimer;
    int decrementAndGetCurrHealth();
    int getCurrHealth();

    int getHealth() const;
    void setHealth(int value);

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
