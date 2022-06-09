#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

#include "headers/enemies_h/balloonchicken.h"
#include "headers/enemies_h/bigchicken.h"
#include "headers/enemies_h/bigegg.h"
#include "headers/enemies_h/chicken.h"
#include "headers/enemies_h/eggchicken.h"
#include "headers/enemies_h/meteor.h"
#include "headers/enemies_h/planetchicken.h"
#include "headers/enemies_h/sideChicken.h"
#include "headers/enemies_h/wavechicken.h"
#include "headers/spaceship_h/spaceship.h"
#include "headers/treets_h/drumstick.h"

class Projectile : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     public:
      Projectile(Spaceship* ss, QTimer* timer, int num);
      QPointF getPosition();

      void colision();
     public slots:
      void move();
      void clean();

     private:
      bool exploded = false;
      int number;
      Spaceship* spaceship;
};

#endif  // PROJECTILE_H
