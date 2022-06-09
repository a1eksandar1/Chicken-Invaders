#ifndef GIFT_H
#define GIFT_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "headers/main_h/mainwindow.h"
#include "headers/spaceship_h/spaceship.h"

class Gift : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     public:
      Gift(MainWindow *parent);

     public slots:
      void move();
      void clean();

     private:
      int width, height;
      MainWindow *mw;
};

#endif  // GIFT_H
