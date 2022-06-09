#ifndef PLANET_H
#define PLANET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPainter>

#include "headers/main_h/mainwindow.h"

class Planet : public QObject, public QGraphicsItem
{
      Q_OBJECT
      Q_INTERFACES(QGraphicsItem)

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
      void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

     public:
      Planet(MainWindow* parent, qreal pos_x, qreal pos_y, qreal height, qreal width, QString name);

      QRectF boundingRect() const override;
      void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

     private:
      qreal pos_x;
      qreal pos_y;
      qreal height;
      qreal width;
      MainWindow* mw;
      QString name;
};
#endif  // PLANET_H
