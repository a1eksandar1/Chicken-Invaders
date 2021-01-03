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
    connect(bChicken, &BigChicken::bigChickenDied, this, &BossGame::onChickenDeath);


}

void BossGame::onChickenDeath()
{
    clear();
    emit closeBossGame();
}

void BossGame::clear()
{

    bChicken = nullptr;
}
