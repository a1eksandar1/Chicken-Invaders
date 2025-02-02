#ifndef BIGEGG_H
#define BIGEGG_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "headers/enemies_h/bigeggbullets.h"
#include "headers/main_h/mainwindow.h"

class bigEgg : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     signals:
      void endOfBigEggGame();

     public:
      bigEgg(MainWindow* parent);
      QTimer* timerForEachBullet;
      QTimer* throwingTimer;
      int decrementAndGetCurrHealth();
      int getCurrHealth();

      int getHealth() const;
      void setHealth(int value);

     public slots:
      void move();
      void clean();
      void throw_bullets();

     private:
      int width;
      int height;
      int health = 100;  // promeni na 100
      bool broken = false;
      int direction = 1;
      MainWindow* mw;
};

#endif  // BIGEGG_H
