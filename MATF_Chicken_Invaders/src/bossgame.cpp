#include "headers/bossgame.h"
#include <QGraphicsScene>

BossGame::BossGame(MainWindow *parent, QGraphicsScene *scene, int numOfShots):
    mw(parent),scene(scene), numOfShots(numOfShots)
{
   bChicken = new BigChicken(mw, numOfShots);
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
