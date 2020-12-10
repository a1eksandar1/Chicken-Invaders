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

    qreal getBoundary_x() const;
    void setBoundary_x(const qreal &value);
    qreal getBoundary_y() const;
    void setBoundary_y(const qreal &value);
    int getMove_x() const;
    void setMove_x(int value);
    int getMove_y() const;
    void setMove_y(int value);

private:
    int move_x;
    int move_y;
    int width, height;
    MainWindow *mw;
    qreal boundary_x;
    qreal boundary_y;
    bool moving;

protected:
    void advance(int step) override;
};

#endif // SIDESPACESHIP_H
