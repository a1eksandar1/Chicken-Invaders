#ifndef PLANETCHICKEN_H
#define PLANETCHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/main_h/mainwindow.h"
#include "headers/enemies_h/egg.h"
#include "headers/treets_h/drumstick.h"
#include "headers/treets_h/gift.h"
#include "headers/treets_h/roastChicken.h"


class PlanetChicken: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    PlanetChicken(MainWindow *parent, QTimer* cleanTimer, int m, int n);
    ~PlanetChicken();

signals:
    void planetChickenDied();

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
    int m, n;
    int imgChange = 0;
    bool rotate = false;
    int orientation=20;
    int width, height;
    int color;
    double t=0, scale = 220;
    bool shot = false;
    int random1;
    int shotCounter;
    QTimer* cleanTimer;
    MainWindow *mw;

public slots:
    void clean();

protected:
    void advance(int step) override;
};

#endif // PLANETCHICKEN_H
