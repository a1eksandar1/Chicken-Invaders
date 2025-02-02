#ifndef METEORSHOWERGAME_H
#define METEORSHOWERGAME_H

#include <QDialog>
#include <QGraphicsScene>
#include <QWidget>

#include "headers/enemies_h/meteor.h"
#include "headers/main_h/mainwindow.h"

class MeteorShowerGame : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     public:
      MeteorShowerGame(MainWindow *parent, QGraphicsScene *scene, int m, int n);
      ~MeteorShowerGame();

      void start();
      void clear();

     signals:
      void closeMeteorShowerGame();

     public slots:
      void onMeteorShot();

     private:
      QVector<QVector<Meteor *>> matrix;
      MainWindow *mw;
      QGraphicsScene *scene;
      int m, n;
      int meteorCounter;
      QTimer *moveMeteorTimer;
      QTimer *cleanMeteorTimer;
};
#endif  // METEORSHOWERGAME_H
