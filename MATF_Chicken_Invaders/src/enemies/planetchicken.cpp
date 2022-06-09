#include "headers/enemies_h/planetchicken.h"

PlanetChicken::PlanetChicken(MainWindow *parent, QTimer *cleanTimer, int m, int n)
    : m(m), n(n), cleanTimer(cleanTimer), mw(parent)
{
      if (mw->isHard())
            this->shotCounter = 2;
      else if (!mw->isHard())
            this->shotCounter = 1;

      this->width = mw->getWidth();
      this->height = mw->getHeight();

      setPixmap(QPixmap(":images/chicken/matf_chicken1.png").scaled(width / 12, height / 9, Qt::KeepAspectRatio));

      setPos((width) / 2 + 130, -height / 9 * (n + 1) + 50);
}

PlanetChicken::~PlanetChicken() {}

void PlanetChicken::die()
{
      shotCounter--;
      if (!shot and shotCounter == 0)
      {
            shot = true;
            emit planetChickenDied();
            setPixmap(QPixmap(":images/chicken/shot_chicken.png").scaled(width / 12, height / 9, Qt::KeepAspectRatio));
            imgChange = 3;

            mw->chickenSound->stop();
            mw->chickenSound->play();
            mw->chickenSound->setVolume(mw->getVolume() == 0 ? 0 : 100);

            Drumstick *drumstick = new Drumstick(mw);
            drumstick->setPos(pos().x(), pos().y() + 100);
            scene()->addItem(drumstick);

            connect(cleanTimer, SIGNAL(timeout()), this, SLOT(clean()));
            cleanTimer->start(200);
      }
}

void PlanetChicken::clean()
{
      scene()->removeItem(this);
      delete this;
}

void PlanetChicken::advance(int step)
{
      if (!step)
      {
            return;
      }

      if (!mw->getFreezeScene())
      {
            if (imgChange == 0)
                  setPixmap(
                      QPixmap(":images/chicken/matf_chicken1.png").scaled(width / 12, height / 9, Qt::KeepAspectRatio));
            if (imgChange == 1)
                  setPixmap(
                      QPixmap(":images/chicken/matf_chicken2.png").scaled(width / 12, height / 9, Qt::KeepAspectRatio));
            if (imgChange == 3) return;

            imgChange = (imgChange + 1) % 2;

            int random_number1 = rand() % 6;
            int random_number2 = rand() % 1000;

            if (random_number1 % 2 == 0 and !rotate)
            {
                  Egg *egg = new Egg(mw);
                  egg->setPos(pos().x() + 20, pos().y() + 100);
                  scene()->addItem(egg);
            }

            if (random_number1 == 5 and rotate)
            {
                  Egg *egg = new Egg(mw);
                  egg->setPos(pos().x() + 20, pos().y() + 100);
                  scene()->addItem(egg);
            }

            if (random_number2 == 5)
            {
                  Gift *gift = new Gift(mw);
                  gift->setPos(pos().x(), pos().y() + 100);
                  scene()->addItem(gift);
            }

            if (pos().y() > height / 2 - 250) rotate = true;

            if (!rotate)
            {
                  setPos(pos().x(), pos().y() + orientation);
            }
            else if (rotate)
            {
                  double x = cos(t) * scale;
                  double y = sin(t) * scale;
                  setPos(width / 2 - 75 + x, height / 2 - 230 + y);
                  t += 0.1;
            }

            if (pos().y() > height) die();
      }
}
