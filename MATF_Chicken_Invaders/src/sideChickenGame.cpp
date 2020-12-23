#include "headers/sideChickenGame.h"
#include <QGraphicsScene>

SideChickenGame::SideChickenGame(MainWindow *parent, QGraphicsScene *scene, int n):
    mw(parent),scene(scene), m(m), n(n), chickenCounter(m*n)
{
        matrix.resize(n);


            for (int i = 0; i < n; i++)
            {
                matrix[i] = new SideChicken(mw,i,n);
            }


}

SideChickenGame::~SideChickenGame()
{

}

QVector<SideChicken *>  SideChickenGame::getMatrix() const
{
    return matrix;
}

void SideChickenGame::start()
{
    for (int i=0; i < n ; i++)
    {

            scene->addItem(matrix[i]);
            connect(matrix[i], &SideChicken::chickenDied, this, &SideChickenGame::onChickenDeath);

    }

}

void SideChickenGame::onChickenDeath()
{
    chickenCounter = chickenCounter - 1;
    if(chickenCounter == 0)
    {
        emit closeChickenMatrixGame();
    }
}

int SideChickenGame::getChickenCounter() const
{
    return chickenCounter;
}

void SideChickenGame::setChickenCounter(int value)
{
    chickenCounter = value;
}

void SideChickenGame::clear()
{
    for(int i = 0; i < n; i++){


            scene->removeItem(matrix[i]);
            matrix[i]= nullptr;

    }
}
