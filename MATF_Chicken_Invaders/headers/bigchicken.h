#ifndef BIGCHICKEN_H
#define BIGCHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/mainwindow.h"
#include "headers/egg.h"


class BigChicken: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    BigChicken(MainWindow *parent, int shotCounter);
    ~BigChicken();

signals:
    void BigchickenDied();

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


public slots:
    void clean();

protected:
    void advance(int step) override;
};

#endif // BIGCHICKEN_H
