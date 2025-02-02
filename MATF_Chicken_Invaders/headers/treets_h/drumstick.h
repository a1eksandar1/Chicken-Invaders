#ifndef DRUMSTICK_H
#define DRUMSTICK_H

#include <math.h>

#include <QGraphicsPixmapItem>
#include <QObject>

#include "headers/main_h/mainwindow.h"

class Drumstick : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     public:
      Drumstick(MainWindow *parent);

      void colision();

      bool getStop() const;
      void setStop(bool value);

     public slots:
      void move();
      void clean();

     private:
      int width, height;
      bool stop = false;
      double angle = 30;
      MainWindow *mw;
};

#endif  // DRUMSTICK_H
