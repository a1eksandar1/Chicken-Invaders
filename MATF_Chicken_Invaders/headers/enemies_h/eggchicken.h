#ifndef EGGCHICKEN_H
#define EGGCHICKEN_H

#include <QApplication>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QObject>
#include <QScreen>
#include <QTimer>

#include "headers/enemies_h/egg.h"
#include "headers/main_h/mainwindow.h"
#include "headers/treets_h/drumstick.h"
#include "headers/treets_h/gift.h"
#include "headers/treets_h/roastChicken.h"

class EggChicken : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     public:
      EggChicken(MainWindow* parent, QTimer* cleanTimer, int m, int n);
      ~EggChicken();

     signals:
      void eggChickenDied();

     public slots:
      void clean();

     public:
      void die();

     private:
      int m, n;
      int imgChange = 0;
      bool isEgg = true;
      int xOrientation = 10, yOrientation = 20;
      int shotCounter;
      int width, height;
      int color;
      double scale = 1, t = 0;
      bool shot = false;
      int random1;
      QTimer* cleanTimer;
      MainWindow* mw;

     protected:
      void advance(int step) override;
};

#endif  // EGGCHICKEN_H
