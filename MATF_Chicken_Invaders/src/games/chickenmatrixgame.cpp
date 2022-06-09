#include "headers/games_h/chickenmatrixgame.h"

#include <QGraphicsScene>

ChickenMatrixGame::ChickenMatrixGame(MainWindow *parent, QGraphicsScene *scene, int m, int n)
    : mw(parent), scene(scene), m(m), n(n), chickenCounter(m * n)
{
      matrix.resize(m);

      this->cleanChickentimer = new QTimer(this);

      for (int i = 0; i < m; i++)
      {
            matrix[i].resize(n);
      }

      for (int i = 0; i < m; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  matrix[i][j] = new Chicken(mw, cleanChickentimer, i, j, m, n);
            }
      }
}

ChickenMatrixGame::~ChickenMatrixGame() {}

void ChickenMatrixGame::start()
{
      for (int i = 0; i < m; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  scene->addItem(matrix[i][j]);
                  connect(matrix[i][j], &Chicken::chickenDied, this, &ChickenMatrixGame::onChickenDeath);
            }
      }
}

void ChickenMatrixGame::onChickenDeath()
{
      chickenCounter = chickenCounter - 1;
      if (chickenCounter == 0)
      {
            emit closeChickenMatrixGame();
            clear();
      }
}

void ChickenMatrixGame::clear()
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
