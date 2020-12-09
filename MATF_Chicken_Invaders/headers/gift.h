#ifndef GIFT_H
#define GIFT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include "headers/mainwindow.h"

class Gift: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Gift(MainWindow *parent);

public slots:
    void move();
    void clean();

private:
    int width, height;
};



#endif // GIFT_H
