#ifndef SIDESPACESHIP_H
#define SIDESPACESHIP_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/mainwindow.h"

class SideSpaceship: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

signals:
    void sidespaceshipStop();

public:
    SideSpaceship(MainWindow *parent);
    ~SideSpaceship();

    qreal getBoundary() const;
    void setBoundary(const qreal &value);

    int getMove() const;
    void setMove(int value);

private:
    int move;
    int width, height;
    MainWindow *mw;
    qreal boundary;
    bool moving;

protected:
    void advance(int step) override;
};

#endif // SIDESPACESHIP_H
