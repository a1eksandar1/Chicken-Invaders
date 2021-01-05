#ifndef PLANETCHICKENGAME_H
#define PLANETCHICKENGAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QDialog>
#include "headers/main_h/mainwindow.h"
#include "headers/enemies_h/planetchicken.h"


class PlanetChickenGame: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    PlanetChickenGame(MainWindow *parent, QGraphicsScene *scene, int num, int pl);
    ~PlanetChickenGame();

    void start();
    void clear();

signals:
    void closePlanetChickenGame();

public slots:
    void onChickenDeath();

private:
    QVector<PlanetChicken*> matrix;
    QVector<PlanetChicken*> rmatrix;
    QGraphicsPixmapItem* planet;
    int width, height;
    MainWindow *mw;
    QGraphicsScene *scene;
    QTimer* cleanChickenTimer;
    int num, count, pl;
    int chickenCounter;

};
#endif // PLANETCHICKENGAME_H
