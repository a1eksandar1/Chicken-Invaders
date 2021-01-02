#ifndef BOSSGAME_H
#define CHICKENMATRIXGAME_H

#include <QWidget>
#include <QGraphicsScene>
#include "spaceship.h"
#include <QDialog>
#include "headers/mainwindow.h"
#include "headers/meteor.h"
#include "headers/bigchicken.h"


class BossGame: public QObject, public QGraphicsPixmapItem
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
    BigChicken * bChicken;
    MainWindow *mw;
    QGraphicsScene *scene;
    int numOfShots;

};
#endif // CHICKENMATRIXGAME_H
