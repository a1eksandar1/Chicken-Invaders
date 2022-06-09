#ifndef WAVECHICKENGAME_H
#define WAVECHICKENGAME_H

#include <QDialog>
#include <QGraphicsScene>
#include <QWidget>

#include "headers/enemies_h/wavechicken.h"
#include "headers/main_h/mainwindow.h"

class WaveChickenGame : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     public:
      WaveChickenGame(MainWindow *parent, QGraphicsScene *scene, int num, int waves);
      ~WaveChickenGame();

      void start();
      void clear();

     signals:
      void closeWaveChickenGame();

     public slots:
      void onChickenDeath();

     private:
      QVector<WaveChicken *> matrix;
      QTimer *cleanChickenTimer;
      MainWindow *mw;
      QGraphicsScene *scene;
      int num, count;
      int waves;
      int chickenCounter;
};
#endif  // WAVECHICKENGAME_H
