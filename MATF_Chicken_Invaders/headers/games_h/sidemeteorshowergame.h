#ifndef SIDEMETEORSHOWERGAME_H
#define SIDEMETEORSHOWERGAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QDialog>
#include "headers/main_h/mainwindow.h"
#include "headers/enemies_h/meteor.h"


class sideMeteorShowerGame: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    sideMeteorShowerGame(MainWindow *parent, QGraphicsScene *scene, int m, int n);
    ~sideMeteorShowerGame();

    QVector<QVector<Meteor *> > getMatrix() const;
    void start();
    void clear();

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
    QTimer* moveMeteorTimer;
    QTimer* cleanMeteorTimer;
};
#endif // SIDEMETEORSHOWERGAME_H
