#include "headers/enemies_h/bigchicken.h"

BigChicken::BigChicken(MainWindow *parent, QTimer *cleanTimer, int shotCounter) : mw(parent), cleanTimer(cleanTimer)
{
      if (mw->isHard())
            this->shotCounter = 2 * shotCounter;
      else if (!mw->isHard())
            this->shotCounter = shotCounter;

      this->width = mw->getWidth();
      this->height = mw->getHeight();

      setPixmap(QPixmap(":images/chicken/bigChicken.png").scaled(height / 2, height / 2, Qt::KeepAspectRatio));

      setPos((width - 30) / 2, -height / 2);
}

BigChicken::~BigChicken() {}

void BigChicken::die()
{
      shotCounter--;

      if (shotCounter > 0)
      {
            setPixmap(QPixmap(":images/chicken/bigChicken2.png").scaled(height / 2, height / 2, Qt::KeepAspectRatio));

            mw->chickenSound->stop();
            mw->chickenSound->play();
            mw->chickenSound->setVolume(mw->getVolume() == 0 ? 0 : 100);

            int random = rand() % 6 - 1;
            Drumstick *drumstick = new Drumstick(mw);
            drumstick->setPos(pos().x() + 100 * random, pos().y() + 200);
            scene()->addItem(drumstick);
      }
      else
      {
            if (!dead)
            {
                  dead = true;
                  emit bigChickenDied();

                  setPixmap(
                      QPixmap(":images/chicken/shot_chicken.png").scaled(height / 2, height / 2, Qt::KeepAspectRatio));
                  imgChange = 3;

                  RoastChicken *roastC = new RoastChicken(mw);
                  roastC->setPos(pos().x() - 100, pos().y() + 100);
                  scene()->addItem(roastC);

                  RoastChicken *roastC2 = new RoastChicken(mw);
                  roastC2->setPos(pos().x() + 350, pos().y() + 0);
                  scene()->addItem(roastC2);

                  RoastChicken *roastC3 = new RoastChicken(mw);
                  roastC3->setPos(pos().x() + 600, pos().y() + 100);
                  scene()->addItem(roastC3);

                  connect(cleanTimer, SIGNAL(timeout()), this, SLOT(clean()));
                  cleanTimer->start(200);
            }
      }
}

int BigChicken::getXOrientation() const { return xOrientation; }

void BigChicken::setXOrientation(int value) { xOrientation = value; }

int BigChicken::getYOrientation() const { return yOrientation; }

void BigChicken::setYOrientation(int value) { yOrientation = value; }

int BigChicken::getWidth() const { return width; }

void BigChicken::setWidth(int value) { width = value; }

void BigChicken::clean()
{
      scene()->removeItem(this);
      delete this;
}

void BigChicken::advance(int step)
{
      if (!step)
      {
            return;
      }

      if (!mw->getFreezeScene())
      {
            if (imgChange == 0)
                  setPixmap(
                      QPixmap(":images/chicken/bigChicken.png").scaled(height / 2, height / 2, Qt::KeepAspectRatio));
            if (imgChange == 1)
                  setPixmap(
                      QPixmap(":images/chicken/bigChicken2.png").scaled(height / 2, height / 2, Qt::KeepAspectRatio));
            if (imgChange == 3) return;

            imgChange = (imgChange + 1) % 2;

            int random_number1 = rand() % 20;
            int random_number2 = rand() % 700;

            if (random_number1 == 5)
            {
                  Egg *egg = new Egg(mw);
                  egg->setPos(pos().x(), pos().y() + 100);
                  scene()->addItem(egg);
            }

            if (random_number2 == 5)
            {
                  Gift *gift = new Gift(mw);
                  gift->setPos(pos().x(), pos().y() + 100);
                  scene()->addItem(gift);
            }

            if (pos().x() > width - width / 8 - height / 2)
                  xOrientation = -10;

            else if (pos().x() <= width / 8)
                  xOrientation = 10;

            if (pos().y() > height / 2)
                  setPos((width - 30) / 2, 0);
            else
                  setPos(pos().x() + xOrientation, pos().y() + yOrientation);
      }
}
