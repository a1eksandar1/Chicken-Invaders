#ifndef BOSSGAME_H
#define CHICKENMATRIXGAME_H

#include <QDialog>
#include <QGraphicsScene>
#include <QWidget>

#include "headers/enemies_h/bigchicken.h"
#include "headers/main_h/mainwindow.h"

class BossGame : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     public:
      BossGame(MainWindow *parent, QGraphicsScene *scene, int numOfShots);
      ~BossGame();
      void start();

      void clear();

     signals:
      void closeBossGame();

     public slots:
      void onChickenDeath();

     private:
      BigChicken *bChicken;
      QTimer *cleanChickenTimer;
      MainWindow *mw;
      QGraphicsScene *scene;
      int numOfShots;
};
#endif  // CHICKENMATRIXGAME_H
