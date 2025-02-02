#ifndef BALLOONGAME_H
#define BALLOONGAME_H

#include <QDialog>
#include <QGraphicsScene>
#include <QWidget>

#include "headers/enemies_h/balloonchicken.h"
#include "headers/main_h/mainwindow.h"

class BalloonGame : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     public:
      BalloonGame(MainWindow *parent, QGraphicsScene *scene, int m, int n);
      ~BalloonGame();

      void start();
      void clear();

     signals:
      void closeBalloonGame();

     public slots:
      void onChickenDeath();

     private:
      QVector<QVector<BalloonChicken *>> matrix;
      MainWindow *mw;
      QGraphicsScene *scene;
      QTimer *cleanChickenTimer;
      int m, n;
      int chickenCounter;
};
#endif  // BALLOONGAME_H
