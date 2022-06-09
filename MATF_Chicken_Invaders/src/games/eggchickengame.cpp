#include "headers/games_h/eggchickengame.h"

int find_rand() { return rand() % 10; }

EggChickenGame::EggChickenGame(MainWindow *parent, QGraphicsScene *scene, int num) : mw(parent), scene(scene), num(num)
{
      this->cleanChickenTimer = new QTimer(this);

      matrix.resize(num);

      srand(time(0));
      std::vector<int> r1;
      r1.resize(num);
      std::vector<int> r2;
      r2.resize(num);

      std::vector<std::vector<bool>> taken;
      taken.resize(10);
      for (int i = 0; i < 10; i++) taken[i].resize(10, false);

      std::generate(r1.begin(), r1.end(), find_rand);
      std::generate(r2.begin(), r2.end(), find_rand);

      int counter = 0;

      for (int i = 0; i < num; i++)
      {
            if (!taken[r1[i]][r2[i]])
            {
                  matrix[counter] = new EggChicken(mw, cleanChickenTimer, r1[i], r2[i]);
                  taken[r1[i]][r2[i]] = true;
                  counter++;
            }
      }
      this->chickenCounter = counter;
      this->count = counter;
}

EggChickenGame::~EggChickenGame() {}

void EggChickenGame::start()
{
      for (int i = 0; i < count; i++)
      {
            scene->addItem(matrix[i]);
            connect(matrix[i], &EggChicken::eggChickenDied, this, &EggChickenGame::onChickenDeath);
      }
}

void EggChickenGame::onChickenDeath()
{
      chickenCounter = chickenCounter - 1;
      if (chickenCounter == 0)
      {
            clear();
            emit closeEggChickenGame();
      }
}

void EggChickenGame::clear()
{
      for (int i = 0; i < count; i++)
      {
            matrix[i] = nullptr;
      }

      matrix.clear();
}
