#ifndef SIDEMETEORSHOWERGAME_H
#define SIDEMETEORSHOWERGAME_H

#include <QWidget>
#include <QGraphicsScene>
#include "spaceship.h"
#include <QDialog>
#include "headers/mainwindow.h"
#include "headers/meteor.h"


class sideMeteorShowerGame: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    sideMeteorShowerGame(MainWindow *parent, QGraphicsScene *scene, int m, int n);
    ~sideMeteorShowerGame();

    QVector<QVector<Meteor *> > getMatrix() const;
    void setMatrix(const QVector<QVector<Meteor *> > &value);
    void start();
    int getMeteorCounter() const;
    void setMeteorCounter(int value);

signals:
    void closeSideMeteorShowerGame();

public slots:
    void onSideMeteorShot();
private:
    QVector<QVector<Meteor*>> matrix;
    MainWindow *mw;
    QGraphicsScene *scene;
    int m, n;
    int meteorCounter;

};
#endif // SIDEMETEORSHOWERGAME_H
