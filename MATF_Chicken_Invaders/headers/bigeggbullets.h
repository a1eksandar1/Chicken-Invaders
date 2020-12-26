#ifndef BIGEGGBULLETS_H
#define BIGEGGBULLETS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "headers/bigegg.h"
#include "headers/mainwindow.h"

class bigEggBullets : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    bigEggBullets(MainWindow *parent, QTimer* timer, int num); // broj oznacava u kom smeru ide metak
    void collision();

public slots:
    void move();
    void clean();

private:
    int number;
    int width;
    int height;
    MainWindow *mw;
};

#endif // BIGEGGBULLETS_H
