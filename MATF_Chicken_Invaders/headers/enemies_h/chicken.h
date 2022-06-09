#ifndef CHICKEN_H
#define CHICKEN_H
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

class Chicken : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     public:
      Chicken(MainWindow* parent, QTimer* cleanTimer, int m, int n, int num1, int num2);
      ~Chicken();

     signals:
      void chickenDied();

     public slots:
      void clean();

     public:
      void die();

     private:
      int m, n, num1, num2;
      int shotCounter;
      int imgChange;
      int orientation = 10;
      int width, height;
      QTimer* cleanTimer;
      bool shot = false;
      MainWindow* mw;

     protected:
      void advance(int step) override;
};

#endif  // CHICKEN_H
