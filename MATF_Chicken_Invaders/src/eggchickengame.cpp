#include "headers/eggchickengame.h"
#include <QGraphicsScene>
#include <algorithm>
#include <vector>


int find_rand()
{
    return rand()%15;
}

EggChickenGame::EggChickenGame(MainWindow *parent, QGraphicsScene *scene,int num):
    mw(parent),scene(scene)
{
        this->num = num;

        matrix.resize(num);
        srand(time(0));
        std::vector<int> r1;
        r1.resize(num);
        std::vector<int> r2;
        r2.resize(num);

        std::vector<std::vector<bool>> taken;
        taken.resize(15);
        for (int i = 0; i < 15; i++)
            taken[i].resize(15, false);

        std::generate(r1.begin(), r1.end(), find_rand);
        std::generate(r2.begin(), r2.end(), find_rand);

        int counter = 0;

        for(int i = 0; i < num; i++)
        {
            if(!taken[r1[i]][r2[i]])
            {
                matrix[counter] = new EggChicken(mw, r1[i], r2[i]);
                taken[r1[i]][r2[i]] = true;
                counter++;
            }

         }
        this->chickenCounter = counter;
        this->count = counter;

}


EggChickenGame::~EggChickenGame()
{

}


void EggChickenGame::start()
{
    for (int i=0; i < count ; i++)
    {
        scene->addItem(matrix[i]);
        connect(matrix[i], &EggChicken::eggChickenDied, this, &EggChickenGame::onChickenDeath);
    }

}

void EggChickenGame::onChickenDeath()
{
    chickenCounter = chickenCounter - 1;
    if(chickenCounter == 0)
    {
        clear();
        emit closeEggChickenGame();
    }
}

int EggChickenGame::getChickenCounter() const
{
    return chickenCounter;
}

void EggChickenGame::setChickenCounter(int value)
{
    chickenCounter = value;
}

void EggChickenGame::clear()
{
    for(int i = 0; i < count; i++){

            matrix[i] = nullptr;

    }

    matrix.clear();

}
