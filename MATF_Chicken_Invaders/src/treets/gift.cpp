#include "headers/treets_h/gift.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QList>
#include <QScreen>
#include <QSoundEffect>
#include <QTimer>

Gift::Gift(MainWindow *parent) : mw(parent)
{
      mw->giftSound->play();

      QTimer *moveTimer = new QTimer(this);
      connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
      moveTimer->start(50);

      this->width = mw->getWidth();
      this->height = mw->getHeight();

      setPixmap(QPixmap(":images/chicken/gift_1.png").scaled(width / 26, width / 26, Qt::KeepAspectRatio));
}

void Gift::move()
{
      if (!mw->getFreezeScene())
      {
            setPos(x(), y() + 10);
            if (pos().y() > height)
            {
                  clean();
            }
      }
}

void Gift::clean()
{
      scene()->removeItem(this);
      delete this;
}
