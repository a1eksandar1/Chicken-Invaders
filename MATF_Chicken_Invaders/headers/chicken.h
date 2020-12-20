#ifndef CHICKEN_H
#define CHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/mainwindow.h"
#include "headers/egg.h"


class Chicken: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Chicken(MainWindow *parent, int m, int n);
    ~Chicken();

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

private:
    int m, n;
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
