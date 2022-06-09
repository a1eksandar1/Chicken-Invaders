#ifndef BALLOONCHICKEN_H
#define BALLOONCHICKEN_H

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

class BalloonChicken : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     public:
      BalloonChicken(MainWindow* parent, QTimer* cleanTimer, int m, int n, int num1, int num2);
      ~BalloonChicken();

     signals:
      void balloonChickenDied();

     public slots:
      void clean();

     public:
      void die();

     private:
      int m, n, num1, num2;
      int imgChange;
      int orientation = 10;
      int width, height;
      bool shot = false;
      int balloonCounter = 3;
      QTimer* cleanTimer;
      int shotCounter;
      MainWindow* mw;

     protected:
      void advance(int step) override;
};

#endif  // BALLOONCHICKEN_H
