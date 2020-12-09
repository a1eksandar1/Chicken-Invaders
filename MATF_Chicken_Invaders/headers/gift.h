#ifndef GIFT_H
#define GIFT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include "headers/mainwindow.h"
#include "headers/spaceship.h"
class Gift: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Gift(MainWindow *parent);

    void colision();
public slots:
    void move();
    void clean();

private:
    int width, height;
    QMediaPlayer * giftSound;
};



#endif // GIFT_H
