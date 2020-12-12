#ifndef METEOR_H
#define METEOR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/mainwindow.h"


class Meteor: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Meteor(MainWindow *parent, int m, int n);
    ~Meteor();

    int getImgChange() const;
    void setImgChange(int value);

    int getOrientation() const;
    void setOrientation(int value);

    bool getShot() const;
    void setShot(bool value);
    void die();


private:
    int m,n;
    int imgChange;
    int orientation = 20;
    int width, height;
    bool shot = false;
    MainWindow *mw;
    QMediaPlayer * chicken_sound;

public slots:
    void clean();
    void move();

protected:
    void advance(int step) override;
};

#endif // METEOR_H
