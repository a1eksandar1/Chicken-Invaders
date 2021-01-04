#ifndef BALLOONCHICKEN_H
#define BALLOONCHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/main_h/mainwindow.h"
#include "headers/enemies_h/egg.h"

#include "headers/treets_h/drumstick.h"
#include "headers/treets_h/gift.h"
#include "headers/treets_h/roastChicken.h"


class BalloonChicken: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    BalloonChicken(MainWindow *parent, QTimer* cleanTimer, int m, int n, int num1, int num2);
    ~BalloonChicken();

signals:
    void balloonChickenDied();

public:
    int getImgChange() const;
    void setImgChange(int value);

    int getOrientation() const;
    void setOrientation(int value);

    bool getShot() const;
    void setShot(bool value);
    void die();

    void move1();
    void move();
private:
    int m, n, num1, num2;
    int imgChange;
    int orientation=10;
    int width, height;
    bool shot = false;
    int balloonCounter=3;
    QTimer* cleanTimer;
    int shotCounter;
    MainWindow *mw;

public slots:
    void clean();

protected:
    void advance(int step) override;
};

#endif // BALLOONCHICKEN_H
