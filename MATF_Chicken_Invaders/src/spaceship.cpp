#include "headers/spaceship.h"

Spaceship::Spaceship() :
    Pressed(false)
{
    setFlag(ItemIsMovable);
}

QRectF Spaceship::boundingRect() const
{
    return QRectF(0,0,100,79);
}

void Spaceship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect(); // da bi mogli rect.getCoords()
    QImage image(":images/spaceships/1.png");
    QBrush brush(image);

    if(Pressed)
    {
        // ako je kliknut
    }
    else
    {
        // ako nije
    }

    painter->fillRect(rect, brush);
    painter->drawRect(rect);
}

void Spaceship::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Spaceship::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
