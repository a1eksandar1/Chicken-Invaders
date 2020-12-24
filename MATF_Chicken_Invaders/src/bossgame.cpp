#include "headers/bossgame.h"
#include <QGraphicsScene>

BossGame::BossGame(MainWindow *parent, QGraphicsScene *scene):
    mw(parent),scene(scene)
{

   bChicken = new BigChicken(mw, 0);
}

BossGame::~BossGame()
{

}

void BossGame::start()
{

    scene->addItem(bChicken);

}

void BossGame::onChickenDeath()
{
    chickenCounter = chickenCounter - 1;
    if(chickenCounter == 0)
    {
        emit closeBossGame();
    }
}

int BossGame::getChickenCounter() const
{
    return chickenCounter;
}

void BossGame::setChickenCounter(int value)
{
    chickenCounter = value;
}

void BossGame::clear()
{


            scene->removeItem(bChicken);
            bChicken = nullptr;

}
