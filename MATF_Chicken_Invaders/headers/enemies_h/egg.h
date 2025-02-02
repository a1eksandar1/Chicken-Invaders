#ifndef EGG_H
#define EGG_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "headers/main_h/mainwindow.h"

class Egg : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     public:
      Egg(MainWindow *parent);

      void colision();

     public slots:
      void move();
      void clean();

     private:
      int width, height;
      bool broken = false;
      MainWindow *mw;
};

#endif  // EGG_H
