#include "headers/enemies_h/sideChicken.h"

SideChicken::SideChicken(MainWindow *parent, QTimer *cleanTimer, int n) : n(n), cleanTimer(cleanTimer), mw(parent)
{
      if (mw->isHard())
            this->shotCounter = 2;
      else if (!mw->isHard())
            this->shotCounter = 1;

      this->width = mw->getWidth();
      this->height = mw->getHeight();

      this->t = 4 * n * 3.14 / 40;
      this->scale = 2 / (3 - cos(2 * t)) * (width / 2.5);

      setPixmap(QPixmap(":images/chicken/leftsideChicken.png").scaled(width / 16, width / 16, Qt::KeepAspectRatio));
      setPos(width / 2 - width / 20 + scale * cos(t), height / 3 + scale * sin(2 * t) / 2);
}

SideChicken::~SideChicken() {}

void SideChicken::die()
{
      shotCounter--;
      if (!shot and shotCounter == 0)
      {
            shot = true;
            emit chickenDied();
            setPixmap(QPixmap(":images/chicken/shot_chicken.png").scaled(width / 16, width / 16, Qt::KeepAspectRatio));
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

void SideChicken::clean()
{
      scene()->removeItem(this);
      delete this;
}

void SideChicken::advance(int step)
{
      if (!step)
      {
            return;
      }

      if (!mw->getFreezeScene())
      {
            int random_number1 = rand() % 300;
            int random_number2 = rand() % 1000;
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

            if (t <= 2 * 3.14)
            {
                  if (t <= 3.14)
                  {
                        if (imgChange == 0)
                              setPixmap(QPixmap(":images/chicken/leftsideChicken.png")
                                            .scaled(width / 16, width / 16, Qt::KeepAspectRatio));
                        else if (imgChange == 1)
                              setPixmap(QPixmap(":images/chicken/leftsideChicken2.png")
                                            .scaled(width / 16, width / 16, Qt::KeepAspectRatio));
                  }
                  else
                  {
                        if (imgChange == 0)
                              setPixmap(QPixmap(":images/chicken/rightsideChicken.png")
                                            .scaled(width / 16, width / 16, Qt::KeepAspectRatio));
                        else if (imgChange == 1)
                              setPixmap(QPixmap(":images/chicken/rightsideChicken2.png")
                                            .scaled(width / 16, width / 16, Qt::KeepAspectRatio));
                  }

                  if (imgChange == 3) return;

                  imgChange = (imgChange + 1) % 2;

                  scale = 2 / (3 - cos(2 * t)) * (width / 2.5);

                  setPos(width / 2 - width / 20 + scale * cos(t), height / 3 + scale * sin(2 * t) / 2);
                  t = t + 3.14 / 40;
            }
            else
            {
                  t = 0;
                  scale = 2 / (3 - cos(2 * t)) * (width / 2.5);

                  setPos(width / 2 - width / 20 + scale * cos(t), height / 3 + scale * sin(2 * t) / 2);
                  t = t + 3.14 / 40;
            }
      }
}
