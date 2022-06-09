#include "headers/enemies_h/bigeggbullets.h"

#include <QApplication>
#include <QScreen>

#include "headers/spaceship_h/spaceship.h"

bigEggBullets::bigEggBullets(MainWindow *parent, QTimer *timer, int num) : number(num), mw(parent)
{
      setPixmap(QPixmap(":images/chicken/bigEggBullet.png"));

      QScreen *screen = QGuiApplication::primaryScreen();
      QRect screenGeometry = screen->geometry();
      height = screenGeometry.height();
      width = screenGeometry.width();

      connect(timer, SIGNAL(timeout()), this, SLOT(move()));
      timer->start(10);
}

void bigEggBullets::move()
{
      if (!mw->getFreezeScene())
      {
            switch (number)
            {
                  case 1:
                        setPos(pos().x() + 3, pos().y());
                        if (pos().x() > width) this->clean();
                        break;
                  case 2:
                        setPos(pos().x() + 2, pos().y() + 2);
                        if (pos().x() > width || pos().y() > height) this->clean();
                        break;
                  case 3:
                        setPos(pos().x(), pos().y() + 3);
                        if (pos().y() > height) this->clean();
                        break;
                  case 4:
                        setPos(pos().x() - 2, pos().y() + 2);
                        if (pos().x() < 0 || pos().y() > height) this->clean();
                        break;
                  case 5:
                        setPos(pos().x() - 3, pos().y());
                        if (pos().x() < 0) this->clean();
                        break;
                  default:
                        break;
            }
      }
}

void bigEggBullets::clean() { delete this; }
