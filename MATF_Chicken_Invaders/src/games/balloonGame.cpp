#include "headers/games_h/balloongame.h"

BalloonGame::BalloonGame(MainWindow *parent, QGraphicsScene *scene, int m, int n)
    : mw(parent), scene(scene), m(m), n(n), chickenCounter(m * n)
{
      cleanChickenTimer = new QTimer(this);
      matrix.resize(m);

      for (int i = 0; i < m; i++)
      {
            matrix[i].resize(n);
      }

      for (int i = 0; i < m; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  matrix[i][j] = new BalloonChicken(mw, cleanChickenTimer, i, j, m, n);
            }
      }
}

BalloonGame::~BalloonGame() {}

void BalloonGame::start()
{
      for (int i = 0; i < m; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  scene->addItem(matrix[i][j]);
                  connect(matrix[i][j], &BalloonChicken::balloonChickenDied, this, &BalloonGame::onChickenDeath);
            }
      }
}

void BalloonGame::onChickenDeath()
{
      chickenCounter = chickenCounter - 1;
      if (chickenCounter == 0)
      {
            emit closeBalloonGame();
      }
}

void BalloonGame::clear()
{
      for (int i = 0; i < m; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  matrix[i][j] = nullptr;
            }
            matrix[i].clear();
      }
      matrix.clear();
}
