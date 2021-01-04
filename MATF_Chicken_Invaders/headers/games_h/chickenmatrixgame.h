#ifndef CHICKENMATRIXGAME_H
#define CHICKENMATRIXGAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QDialog>
#include "headers/main_h/mainwindow.h"
#include "headers/enemies_h/chicken.h"


class ChickenMatrixGame: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    ChickenMatrixGame(MainWindow *parent, QGraphicsScene *scene, int m, int n);
    ~ChickenMatrixGame();

    QVector<QVector<Chicken *> > getMatrix() const;
    void setMatrix(const QVector<QVector<Chicken *> > &value);
    void start();

    int getChickenCounter() const;
    void setChickenCounter(int value);

    void clear();

signals:
    void closeChickenMatrixGame();

public slots:
    void onChickenDeath();

private:
    QVector<QVector<Chicken*>> matrix;
    QTimer* cleanChickentimer;
    MainWindow *mw;
    QGraphicsScene *scene;
    int m, n;
    int chickenCounter;

};
#endif // CHICKENMATRIXGAME_H
