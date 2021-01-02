#ifndef WAVECHICKEN_H
#define WAVECHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/mainwindow.h"
#include "headers/egg.h"


class WaveChicken: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    WaveChicken(MainWindow *parent, int m, int n);
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

private:
    int m, n;
    int imgChange = 0;
    bool isEgg = true;
    int orientation=20;
    int width, height;
    int color;
    double scale=1, t=0;
    bool shot = false;
    int random1;
    MainWindow *mw;

public slots:
    void clean();

protected:
    void advance(int step) override;
};

#endif // WAVECHICKEN_H
