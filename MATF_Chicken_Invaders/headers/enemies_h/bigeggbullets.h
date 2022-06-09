#ifndef BIGEGGBULLETS_H
#define BIGEGGBULLETS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

#include "headers/enemies_h/bigegg.h"
#include "headers/main_h/mainwindow.h"

class bigEggBullets : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT

     public:
      bigEggBullets(MainWindow *parent, QTimer *timer, int num);  // broj oznacava u kom smeru ide metak

     public slots:
      void move();
      void clean();

     private:
      int number;
      int width;
      int height;
      MainWindow *mw;
};

#endif  // BIGEGGBULLETS_H
