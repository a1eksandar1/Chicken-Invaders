#ifndef SIDECHICKEN_H
#define SIDECHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/main_h/mainwindow.h"
#include "headers/enemies_h/egg.h"
#include "headers/treets_h/drumstick.h"
#include "headers/treets_h/gift.h"
#include "headers/treets_h/roastChicken.h"


class SideChicken: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    SideChicken(MainWindow *parent, QTimer* cleanTimer, int n);
    ~SideChicken();

signals:
    void chickenDied();

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
    int n, num;
    int imgChange;
    int orientation=10;
    int shotCounter;
    int width, height;
    bool shot = false;
    double scale=1, t=0;
    QTimer *cleanTimer;
    MainWindow *mw;

public slots:
    void clean();

protected:
    void advance(int step) override;
};

#endif // SIDECHICKEN_H
