#ifndef SIDECHICKENGAME_H
#define SIDECHICKENGAME_H

#include <QWidget>
#include <QGraphicsScene>
#include "spaceship.h"
#include <QDialog>
#include "headers/mainwindow.h"
#include "headers/meteor.h"
#include "headers/sideChicken.h"


class SideChickenGame: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    SideChickenGame(MainWindow *parent, QGraphicsScene *scene, int n);
    ~SideChickenGame();

    QVector<SideChicken *> getMatrix() const;
    void setMatrix(const QVector<SideChicken * > &value);
    void start();

    int getChickenCounter() const;
    void setChickenCounter(int value);

    void clear();

signals:
    void closeChickenMatrixGame();

public slots:
    void onChickenDeath();

private:
    QVector<SideChicken*> matrix;
    MainWindow *mw;
    QGraphicsScene *scene;
    int imgChange = 1;
    int side = 1;
    int m, n;
    int chickenCounter;

};
#endif // SIDECHICKENGAME_H
