#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>
#include <QPainter>
#include <QTimer>

#include "headers/enemies_h/bigchicken.h"
#include "headers/enemies_h/bigeggbullets.h"
#include "headers/main_h/mainwindow.h"
#include "headers/treets_h/drumstick.h"
#include "headers/treets_h/gift.h"
#include "headers/treets_h/roastChicken.h"

class Spaceship : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     signals:
      void spaceshipDestroyed();
      void changeScore(int step);
      void spaceshipHited();

     public:
      Spaceship(MainWindow* parent);
      QPointF getPosition();
      void throw_projectile();
      bool getThrowingAllowed();
      void setThrowingAllowed(bool isAllowed);
      qreal yStart();
      int decreaseLivesNumAndGetCurrNumLives();
      void setStartingPosition(int pos_x, int pos_y);
      int getStartingXPos();
      int getStartingYPos();
      void collision();
      void checkIfSpaceshipDestroyed();
      bool isCurrentlyDestroyed = false;
      void setInvisible();
      void setNumOfLives(int num);

     public:
      MainWindow* mw;
      int getProjectilesLevel() const;
      void setProjectilesLevel(int value);
      int getDirection();
      void setDirection(int d);
      void start_moving_timer();
      void stop_moving_timer();
      void revertProjectilesLevel();

     public slots:
      void move();
      void enableSpaceshipAfterDestroying();

     private:
      bool alive = true;
      QTimer* throwingProjectilesTimer;
      QTimer* moving_timer;
      int projectilesLevel;
      QTimer* destroyedTimer;
      bool throwingAllowed = true;
      int numberOfLives = 3;
      int startingXPosition;
      int startingYPosition;
      int width, height;

     protected:
      void advance(int step) override;
      int direction;  // possible values -1, 0, 1
};

#endif  // SPACESHIP_H
