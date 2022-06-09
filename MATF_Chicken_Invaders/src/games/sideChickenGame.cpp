#include "headers/games_h/sideChickenGame.h"

#include <QGraphicsScene>

SideChickenGame::SideChickenGame(MainWindow *parent, QGraphicsScene *scene, int n)
    : mw(parent), scene(scene), n(n), chickenCounter(n)
{
      this->cleanChickenTimer = new QTimer(this);

      matrix.resize(n);

      for (int i = 0; i < n; i++)
      {
            matrix[i] = new SideChicken(mw, cleanChickenTimer, i);
      }
}

SideChickenGame::~SideChickenGame() {}

void SideChickenGame::start()
{
      for (int i = 0; i < n; i++)
      {
            scene->addItem(matrix[i]);
            connect(matrix[i], &SideChicken::chickenDied, this, &SideChickenGame::onChickenDeath);
      }
}

void SideChickenGame::onChickenDeath()
{
      chickenCounter = chickenCounter - 1;
      if (chickenCounter == 0)
      {
            clear();
            emit closeSideChickenGame();
      }
}

void SideChickenGame::clear()
{
      for (int i = 0; i < n; i++)
      {
            matrix[i] = nullptr;
      }
      matrix.clear();
}
