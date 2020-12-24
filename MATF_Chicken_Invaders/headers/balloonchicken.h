#ifndef BALLOONCHICKEN_H
#define BALLOONCHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/mainwindow.h"
#include "headers/egg.h"


class BalloonChicken: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    BalloonChicken(MainWindow *parent, int m, int n, int num);
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
    int m, n, num;
    int imgChange;
    int orientation=10;
    int width, height;
    bool shot = false;
    int balloonCounter=3;
    MainWindow *mw;

public slots:
    void clean();

protected:
    void advance(int step) override;
};

#endif // BALLOONCHICKEN_H
