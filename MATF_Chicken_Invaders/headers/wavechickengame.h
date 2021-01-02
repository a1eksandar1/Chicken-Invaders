#ifndef WAVECHICKENGAME_H
#define WAVECHICKENGAME_H

#include <QWidget>
#include <QGraphicsScene>
#include "spaceship.h"
#include <QDialog>
#include "headers/mainwindow.h"
#include "headers/wavechicken.h"


class WaveChickenGame: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    WaveChickenGame(MainWindow *parent, QGraphicsScene *scene, int num, int waves);
    ~WaveChickenGame();
    void start();

    int getChickenCounter() const;
    void setChickenCounter(int value);

    void clear();

signals:
    void closeWaveChickenGame();

public slots:
    void onChickenDeath();

private:
    QVector<WaveChicken*> matrix;
    QVector<WaveChicken*> rmatrix;
    MainWindow *mw;
    QGraphicsScene *scene;
    int num, count;
    int waves;
    int chickenCounter;

};
#endif // WAVECHICKENGAME_H
