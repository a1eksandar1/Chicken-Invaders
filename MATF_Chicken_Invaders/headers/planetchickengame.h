#ifndef PLANETCHICKENGAME_H
#define PLANETCHICKENGAME_H

#include <QWidget>
#include <QGraphicsScene>
#include "spaceship.h"
#include <QDialog>
#include "headers/mainwindow.h"
#include "headers/planetchicken.h"


class PlanetChickenGame: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    PlanetChickenGame(MainWindow *parent, QGraphicsScene *scene, int num, int pl);
    ~PlanetChickenGame();
    void start();

    int getChickenCounter() const;
    void setChickenCounter(int value);

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
    int num, count, pl;
    int chickenCounter;

};
#endif // PLANETCHICKENGAME_H
