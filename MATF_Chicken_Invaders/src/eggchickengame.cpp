#include "headers/eggchickengame.h"
#include <QGraphicsScene>

EggChickenGame::EggChickenGame(MainWindow *parent, QGraphicsScene *scene,int num):
    mw(parent),scene(scene), num(num), chickenCounter(num)
{
        matrix.resize(num);

        for (int i=0; i < num ; i++)
        {
                matrix[i] = new EggChicken(mw, i);
        }

}

EggChickenGame::~EggChickenGame()
{

}


void EggChickenGame::start()
{
    for (int i=0; i < num ; i++)
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
    for(int i = 0; i < num; i++){

            scene->removeItem(matrix[i]);
            matrix[i] = nullptr;

    }

}
