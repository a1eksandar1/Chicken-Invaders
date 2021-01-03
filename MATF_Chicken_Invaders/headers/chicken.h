#ifndef CHICKEN_H
#define CHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/mainwindow.h"
#include "headers/egg.h"
#include "headers/gift.h"
#include "headers/drumstick.h"


class Chicken: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Chicken(MainWindow *parent, int m, int n, int num1, int num2);
    ~Chicken();

signals:
    void chickenDied();

public:
    void die();

    void move1();
    void move();
private:
    int m, n, num1, num2;
    int shotCounter;
    int imgChange;
    int orientation=10;
    int width, height;
    bool shot = false;
    MainWindow *mw;

public slots:
    void clean();

protected:
    void advance(int step) override;
};

#endif // CHICKEN_H
