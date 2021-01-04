#ifndef BIGEGGBULLETS_H
#define BIGEGGBULLETS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "headers/main_h/mainwindow.h"
#include "headers/enemies_h/bigegg.h"


class bigEggBullets : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    bigEggBullets(MainWindow *parent, QTimer* timer, int num); // broj oznacava u kom smeru ide metak

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
