#ifndef CHICKENMATRIXGAME_H
#define CHICKENMATRIXGAME_H

#include <QDialog>
#include <QGraphicsScene>
#include <QWidget>

#include "headers/enemies_h/chicken.h"
#include "headers/main_h/mainwindow.h"

class ChickenMatrixGame : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     public:
      ChickenMatrixGame(MainWindow *parent, QGraphicsScene *scene, int m, int n);
      ~ChickenMatrixGame();

      QVector<QVector<Chicken *>> getMatrix() const;

      void start();
      void clear();

     signals:
      void closeChickenMatrixGame();

     public slots:
      void onChickenDeath();

     private:
      QVector<QVector<Chicken *>> matrix;
      QTimer *cleanChickentimer;
      MainWindow *mw;
      QGraphicsScene *scene;
      int m, n;
      int chickenCounter;
};
#endif  // CHICKENMATRIXGAME_H
