#ifndef METEOR_H
#define METEOR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/mainwindow.h"
#include "headers/spaceship.h"

class Meteor: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Meteor(MainWindow *parent, int m, int n, int v);
    ~Meteor();

    int getImgChange() const;
    void setImgChange(int value);

    bool getShot() const;
    void setShot(bool value);
    void die();

signals:
    void meteorShot();

private:
    int m, n, x, v, random1, random2;
    int imgChange;
    int speed = 25;
    int width, height;
    bool shot = false;
    MainWindow *mw;
    QMediaPlayer * meteor_sound;

public slots:
    void clean();
    void move1();

    void move2();
protected:
    void advance(int step) override;
};

#endif // METEOR_H
