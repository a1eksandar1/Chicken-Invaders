#include "headers/enemies_h/egg.h"

#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>
#include <QScreen>
#include <QSoundEffect>
#include <QTimer>

#include "headers/spaceship_h/spaceship.h"

Egg::Egg(MainWindow *parent) : mw(parent)
{
      QTimer *moveTimer = new QTimer(this);
      connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
      moveTimer->start(50);

      this->width = mw->getWidth();
      this->height = mw->getHeight();

      setPixmap(QPixmap(":images/chicken/egg_1.png").scaled(width / 32, width / 32, Qt::KeepAspectRatio));
}

void Egg::move()
{
      if (!mw->getFreezeScene())
      {
            if (!broken) setPos(x(), y() + 10);

            if (pos().y() > height - 100)
            {
                  if (!broken)
                  {
                        mw->eggSound->play();
                        broken = true;
                  }

                  setPixmap(QPixmap(":images/chicken/egg_2.png").scaled(width / 20, width / 20, Qt::KeepAspectRatio));

                  QTimer *cleanTimer = new QTimer(this);
                  connect(cleanTimer, SIGNAL(timeout()), this, SLOT(clean()));
                  cleanTimer->start(1000);
            }
      }
}

void Egg::clean()
{
      scene()->removeItem(this);
      delete this;
}
