#include "headers/games_h/sidemeteorshowergame.h"

#include <headers/games_h/sidemeteorshowergame.h>

#include <QGraphicsScene>

sideMeteorShowerGame::sideMeteorShowerGame(MainWindow *parent, QGraphicsScene *scene, int m, int n)
    : mw(parent), scene(scene), m(m), n(n), meteorCounter(m * n)
{
      this->moveMeteorTimer = new QTimer(this);
      this->cleanMeteorTimer = new QTimer(this);
      matrix.resize(m);

      for (int i = 0; i < m; i++)
      {
            matrix[i].resize(n);
      }

      for (int i = 0; i < m; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  matrix[i][j] = new Meteor(mw, moveMeteorTimer, cleanMeteorTimer, i, j, 2);
            }
      }
}

sideMeteorShowerGame::~sideMeteorShowerGame() {}

void sideMeteorShowerGame::start()
{
      for (int i = 0; i < m; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  scene->addItem(matrix[i][j]);
                  connect(matrix[i][j], &Meteor::meteorShot, this, &sideMeteorShowerGame::onSideMeteorShot);
            }
      }
}

void sideMeteorShowerGame::onSideMeteorShot()
{
      meteorCounter = meteorCounter - 1;

      if (meteorCounter == 0)
      {
            clear();
            emit closeSideMeteorShowerGame();
      }
}

void sideMeteorShowerGame::clear()
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
