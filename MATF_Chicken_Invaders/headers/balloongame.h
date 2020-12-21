#ifndef BALLOONGAME_H
#define BALLOONGAME_H

#include <QWidget>
#include <QGraphicsScene>
#include "spaceship.h"
#include <QDialog>
#include "headers/mainwindow.h"
#include "headers/meteor.h"
#include "headers/balloonchicken.h"


class BalloonGame: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    BalloonGame(MainWindow *parent, QGraphicsScene *scene, int m, int n);
    ~BalloonGame();

    QVector<QVector<BalloonChicken *> > getMatrix() const;
    void setMatrix(const QVector<QVector<BalloonChicken *> > &value);
    void start();

    int getChickenCounter() const;
    void setChickenCounter(int value);

    void clear();

signals:
    void closeBalloonGame();

public slots:
    void onChickenDeath();

private:
    QVector<QVector<BalloonChicken*>> matrix;
    MainWindow *mw;
    QGraphicsScene *scene;
    int m, n;
    int chickenCounter;

};
#endif // BALLOONGAME_H
