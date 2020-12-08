#ifndef PLANET_H
#define PLANET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "headers/mainwindow.h"
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPainter>

class Planet : public QObject, public QGraphicsItem
{

    Q_OBJECT

signals:
    void neptuneClicked();
    void plutoClicked();
    void uranusClicked();
    void saturnClicked();
    void jupiterClicked();
    void marsClicked();
    void earthClicked();
    void venusClicked();
    void mercuryClicked();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

public:
    Planet(MainWindow *parent, qreal pos_x, qreal pos_y, qreal height, qreal width, QString name);

    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
    qreal pos_x;
    qreal pos_y;
    qreal height;
    qreal width;
    MainWindow *mw;
    QString name;
};
#endif // PLANET_H
