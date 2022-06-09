#include "headers/treets_h/drumstick.h"

#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>
#include <QScreen>
#include <QSoundEffect>
#include <QTimer>

#include "headers/spaceship_h/spaceship.h"

Drumstick::Drumstick(MainWindow *parent) : mw(parent)
{
      QTimer *moveTimer = new QTimer(this);
      connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
      moveTimer->start(50);

      this->width = mw->getWidth();
      this->height = mw->getHeight();
      setPixmap(QPixmap(":images/chicken/drumstick.png").scaled(width / 22, width / 22, Qt::KeepAspectRatio));
}

void Drumstick::move()
{
      if (!mw->getFreezeScene())
      {
            QTransform transform;
            transform = transform.rotate(angle);
            setPixmap(QPixmap(":images/chicken/drumstick.png")
                          .scaled(width / 22, width / 22, Qt::KeepAspectRatio)
                          .transformed(transform));
            if (!stop)
            {
                  angle += 20;
            }

            int random = rand() % 2;
            if (random == 1)
                  random = 1;
            else
                  random = -1;

            if (pos().y() > height - 110)
            {
                  setStop(true);
                  QTimer *cleanTimer = new QTimer(this);
                  connect(cleanTimer, SIGNAL(timeout()), this, SLOT(clean()));
                  cleanTimer->start(1000);
            }
            else
                  setPos(x() + 10 * random, y() + 20);
      }
}

void Drumstick::clean()
{
      scene()->removeItem(this);
      delete this;
}

bool Drumstick::getStop() const { return stop; }

void Drumstick::setStop(bool value) { stop = value; }
