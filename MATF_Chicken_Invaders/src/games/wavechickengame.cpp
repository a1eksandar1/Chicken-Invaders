#include "headers/games_h/wavechickengame.h"
#include <QGraphicsScene>
#include <algorithm>
#include <vector>


WaveChickenGame::WaveChickenGame(MainWindow *parent, QGraphicsScene *scene, int num, int waves):
    mw(parent), scene(scene), num(num), waves(waves), chickenCounter(waves*num)
{
    this->cleanChickenTimer = new QTimer(this);

    if (waves == 1)
    {
        matrix.resize(num);
        for (int i = 0; i < num; i++)
        {
            matrix[i] = new WaveChicken(mw, cleanChickenTimer, i, i);
        }
    }

    else if (waves == 2)
    {
        matrix.resize(2*num);
        for (int i = 0; i < num; i++)
        {
            matrix[i] = new WaveChicken(mw,cleanChickenTimer, i, i);
        }
        for (int i = num; i < 2*num; i++)
        {
            matrix[i] = new WaveChicken(mw,cleanChickenTimer, i-num, i-num+1);
        }
    }

    else if (waves == 3)
    {
        matrix.resize(3*num);
        for (int i = 0; i < num; i++)
        {
            matrix[i] = new WaveChicken(mw,cleanChickenTimer, i, i);

        }
        for (int i = num; i < 2*num; i++)
        {
            matrix[i] = new WaveChicken(mw,cleanChickenTimer, i-num, i-num+1);

        }
        for (int i = 2*num; i < 3*num; i++)
        {
            matrix[i] = new WaveChicken(mw,cleanChickenTimer, i-2*num, i-2*num+2);

        }
    }
}

WaveChickenGame::~WaveChickenGame()
{

}


void WaveChickenGame::start()
{
    for (int i=0; i < waves*num ; i++)
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

void WaveChickenGame::clear()
{
    for(int i = 0; i <waves*num; i++)
    {
        matrix[i] = nullptr;
    }

    matrix.clear();
}
