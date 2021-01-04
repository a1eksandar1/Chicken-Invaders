#ifndef BIGCHICKEN_H
#define BIGCHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/main_h/mainwindow.h"
#include "headers/enemies_h/egg.h"

#include "headers/treets_h/drumstick.h"
#include "headers/treets_h/gift.h"
#include "headers/treets_h/roastChicken.h"


class BigChicken: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    BigChicken(MainWindow *parent,QTimer *cleanTimer, int shotCounter);
    ~BigChicken();

signals:
    void bigChickenDied();

public:
    int getImgChange() const;
    void setImgChange(int value);

    int getXOrientation() const;
    void setXOrientation(int value);

    void die();

    void move1();
    void move();
    int getYOrientation() const;
    void setYOrientation(int value);

    int getShotCounter() const;
    void setShotCounter(int value);

    int getWidth() const;
    void setWidth(int value);

private:
    MainWindow *mw;
    int m, n;
    int imgChange;
    int xOrientation=10;
    int yOrientation=15;
    int width, height;
    int shotCounter;
    bool dead = false;
    QTimer* cleanTimer;


public slots:
    void clean();

protected:
    void advance(int step) override;
};

#endif // BIGCHICKEN_H
