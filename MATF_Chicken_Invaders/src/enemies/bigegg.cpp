#include "headers/enemies_h/bigegg.h"

#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>
#include <QScreen>
#include <QSoundEffect>

#include "headers/spaceship_h/projectile.h"

bigEgg::bigEgg(MainWindow *parent) : mw(parent)
{
      setPixmap(QPixmap(":images/chicken/bigEgg.png").scaled(500, 500, Qt::KeepAspectRatio));

      QTimer *moveTimer = new QTimer(this);
      connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
      moveTimer->start(50);

      timerForEachBullet = new QTimer;

      throwingTimer = new QTimer;
      connect(throwingTimer, SIGNAL(timeout()), this, SLOT(throw_bullets()));
      throwingTimer->start(2500);

      QScreen *screen = QGuiApplication::primaryScreen();
      QRect screenGeometry = screen->geometry();
      int height = screenGeometry.height();
      int width = screenGeometry.width();

      this->width = width;
      this->height = height;

      setPos((width - 30) / 2, -500);
}

void bigEgg::throw_bullets()
{
      if (!mw->getFreezeScene())
      {
            std::vector<bigEggBullets *> big_egg_bullets;
            for (int i = 1; i < 6; i++)
            {
                  big_egg_bullets.push_back(new bigEggBullets(mw, timerForEachBullet, i));
            }

            big_egg_bullets[0]->setPos(pos().x() + 440, pos().y() + 250);
            big_egg_bullets[1]->setPos(pos().x() + 385, pos().y() + 430);
            big_egg_bullets[2]->setPos(pos().x() + 185, pos().y() + 500);
            big_egg_bullets[3]->setPos(pos().x(), pos().y() + 430);
            big_egg_bullets[4]->setPos(pos().x() - 50, pos().y() + 250);

            for (auto bull : big_egg_bullets) scene()->addItem(bull);
      }
}

int bigEgg::getHealth() const { return health; }

void bigEgg::setHealth(int value) { health = value; }

void bigEgg::move()
{
      if (!mw->getFreezeScene())
      {
            if (direction > 0)
            {  // ide udesno
                  if (pos().x() > width - width / 8 - 500) direction = -direction;
            }
            else
            {  // ide ulevo
                  if (pos().x() <= width / 8) direction = -direction;
            }

            setPos(pos().x() + 3 * direction, pos().y());
      }
}

void bigEgg::clean()
{
      scene()->removeItem(this);
      delete this;
}

int bigEgg::decrementAndGetCurrHealth() { return --health; }

int bigEgg::getCurrHealth() { return health; }
