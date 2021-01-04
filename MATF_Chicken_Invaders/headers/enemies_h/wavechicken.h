#ifndef WAVECHICKEN_H
#define WAVECHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/main_h/mainwindow.h"
#include "headers/enemies_h/egg.h"
#include "headers/treets_h/drumstick.h"
#include "headers/treets_h/gift.h"
#include "headers/treets_h/roastChicken.h"


class WaveChicken: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    WaveChicken(MainWindow *parent,QTimer* cleanTimer, int m, int n);
    ~WaveChicken();

signals:
    void waveChickenDied();

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

    bool getCanBeshot() const;
    void setCanBeshot(bool value);

private:
    int m, n;
    int imgChange = 0;
    bool wave = true;
    int shotCounter;
    bool canBeshot = false;

    int orientation=20;
    int width, height;
    int color;
    double scale=1, t=0;
    bool shot = false;
    int random1;
    QTimer* cleanTimer;
    MainWindow *mw;

public slots:
    void clean();

protected:
    void advance(int step) override;
};

#endif // WAVECHICKEN_H
