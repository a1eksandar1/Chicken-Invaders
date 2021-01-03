#ifndef PLANETCHICKEN_H
#define PLANETCHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/mainwindow.h"
#include "headers/egg.h"


class PlanetChicken: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    PlanetChicken(MainWindow *parent, int m, int n);
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
    MainWindow *mw;

public slots:
    void clean();

protected:
    void advance(int step) override;
};

#endif // PLANETCHICKEN_H
