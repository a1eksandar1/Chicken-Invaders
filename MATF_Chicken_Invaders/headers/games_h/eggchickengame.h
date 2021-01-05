#ifndef EGGCHICKENGAME_H
#define EGGCHICKENGAME_H

#include <algorithm>
#include <vector>
#include <QWidget>
#include <QGraphicsScene>
#include <QDialog>

#include "headers/main_h/mainwindow.h"
#include "headers/enemies_h/eggchicken.h"


class EggChickenGame: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    EggChickenGame(MainWindow *parent, QGraphicsScene *scene, int num);
    ~EggChickenGame();

    void start();
    void clear();

signals:
    void closeEggChickenGame();

public slots:
    void onChickenDeath();

private:
    QVector<EggChicken*> matrix;
    MainWindow *mw;
    QGraphicsScene *scene;
    int num, count;
    int chickenCounter;
    QTimer* cleanChickenTimer;

};
#endif // EGGCHICKENGAME_H
