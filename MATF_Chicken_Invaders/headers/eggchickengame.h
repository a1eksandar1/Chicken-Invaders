#ifndef EGGCHICKENGAME_H
#define EGGCHICKENGAME_H

#include <QWidget>
#include <QGraphicsScene>
#include "spaceship.h"
#include <QDialog>
#include "headers/mainwindow.h"
#include "headers/eggchicken.h"


class EggChickenGame: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    EggChickenGame(MainWindow *parent, QGraphicsScene *scene, int num);
    ~EggChickenGame();
    void start();

    int getChickenCounter() const;
    void setChickenCounter(int value);

    void clear();

signals:
    void closeEggChickenGame();

public slots:
    void onChickenDeath();

private:
    QVector<EggChicken*> matrix;
    MainWindow *mw;
    QGraphicsScene *scene;
    int num;
    int chickenCounter;

};
#endif // EGGCHICKENGAME_H
