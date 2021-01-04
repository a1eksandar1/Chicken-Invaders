#ifndef BALLOONGAME_H
#define BALLOONGAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QDialog>
#include "headers/main_h/mainwindow.h"
#include "headers/enemies_h/balloonchicken.h"

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
    QTimer* cleanChickenTimer;
    int m, n;
    int chickenCounter;

};
#endif // BALLOONGAME_H
