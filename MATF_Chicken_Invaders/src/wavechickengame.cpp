#include "headers/wavechickengame.h"
#include <QGraphicsScene>
#include <algorithm>
#include <vector>



WaveChickenGame::WaveChickenGame(MainWindow *parent, QGraphicsScene *scene,int num):
    mw(parent),scene(scene), num(num), chickenCounter(num)
{

    matrix.resize(num);
    for (int i = 0; i < num; i++)
    {
        matrix[i] = new WaveChicken(mw, i, i);

    }

}


WaveChickenGame::~WaveChickenGame()
{

}


void WaveChickenGame::start()
{
    for (int i=0; i < num ; i++)
    {
        scene->addItem(matrix[i]);

        connect(matrix[i], &WaveChicken::waveChickenDied, this, &WaveChickenGame::onChickenDeath);

    }

}

void WaveChickenGame::onChickenDeath()
{
    chickenCounter = chickenCounter - 1;
    if(chickenCounter == 0)
    {
        clear();
        emit closeWaveChickenGame();
    }
}

int WaveChickenGame::getChickenCounter() const
{
    return chickenCounter;
}

void WaveChickenGame::setChickenCounter(int value)
{
    chickenCounter = value;
}

void WaveChickenGame::clear()
{
    for(int i = 0; i < num; i++){

            matrix[i] = nullptr;

    }

    matrix.clear();

}
