#ifndef SIDECHICKEN_H
#define SIDECHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/mainwindow.h"
#include "headers/egg.h"


class SideChicken: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    SideChicken(MainWindow *parent, int n, int num);
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
    int m, n, num;
    int imgChange;
    int orientation=10;
    int width, height;
    bool shot = false;
    double scale=1, t=0;
    MainWindow *mw;

public slots:
    void clean();

protected:
    void advance(int step) override;
};

#endif // SIDECHICKEN_H
