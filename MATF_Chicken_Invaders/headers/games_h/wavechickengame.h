#ifndef WAVECHICKENGAME_H
#define WAVECHICKENGAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QDialog>
#include "headers/main_h/mainwindow.h"
#include "headers/enemies_h/wavechicken.h"


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
    QTimer* cleanChickenTimer;
    MainWindow *mw;
    QGraphicsScene *scene;
    int num, count;
    int waves;
    int chickenCounter;

};
#endif // WAVECHICKENGAME_H
