#ifndef METEORSHOWERGAME_H
#define METEORSHOWERGAME_H

#include <QWidget>
#include <QGraphicsScene>
#include "spaceship.h"
#include <QDialog>
#include "headers/mainwindow.h"
#include "headers/meteor.h"


class MeteorShowerGame: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    MeteorShowerGame(MainWindow *parent, QGraphicsScene *scene, int m, int n);
    ~MeteorShowerGame();

    QVector<QVector<Meteor *> > getMatrix() const;
    void setMatrix(const QVector<QVector<Meteor *> > &value);
    void start();

    int getMeteorCounter() const;
    void setMeteorCounter(int value);

signals:
    void closeMeteorShowerGame();

public slots:
    void onMeteorShot();

private:
    QVector<QVector<Meteor*>> matrix;
    MainWindow *mw;
    QGraphicsScene *scene;
    int m, n;
    int meteorCounter;

};
#endif // METEORSHOWERGAME_H
