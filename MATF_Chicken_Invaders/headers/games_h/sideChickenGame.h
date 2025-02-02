#ifndef SIDECHICKENGAME_H
#define SIDECHICKENGAME_H

#include <QDialog>
#include <QGraphicsScene>
#include <QWidget>

#include "headers/enemies_h/sideChicken.h"
#include "headers/main_h/mainwindow.h"

class SideChickenGame : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     public:
      SideChickenGame(MainWindow *parent, QGraphicsScene *scene, int n);
      ~SideChickenGame();

      void start();
      void clear();

     signals:
      void closeSideChickenGame();

     public slots:
      void onChickenDeath();

     private:
      QVector<SideChicken *> matrix;
      MainWindow *mw;
      QGraphicsScene *scene;
      QTimer *cleanChickenTimer;
      int imgChange = 1;
      int side = 1;
      int m, n;
      int chickenCounter;
};
#endif  // SIDECHICKENGAME_H
