#include "headers/chickenmatrixgame.h"
#include <QGraphicsScene>

ChickenMatrixGame::ChickenMatrixGame(MainWindow *parent, QGraphicsScene *scene,int m, int n):
    mw(parent),scene(scene), m(m), n(n), chickenCounter(m*n)
{
        matrix.resize(m);

        for (int i=0; i < m; i++)
        {
            matrix[i].resize(n);
        }

        for (int i=0; i < m ; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = new Chicken(mw,i,j, n);
            }
        }

}

ChickenMatrixGame::~ChickenMatrixGame()
{

}

QVector<QVector<Chicken *> > ChickenMatrixGame::getMatrix() const
{
    return matrix;
}

void ChickenMatrixGame::start()
{
    for (int i=0; i < m ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scene->addItem(matrix[i][j]);
            connect(matrix[i][j], &Chicken::chickenDied, this, &ChickenMatrixGame::onChickenDeath);
        }
    }

}

void ChickenMatrixGame::onChickenDeath()
{
    chickenCounter = chickenCounter - 1;
    if(chickenCounter == 0)
    {
        emit closeChickenMatrixGame();
    }
}

int ChickenMatrixGame::getChickenCounter() const
{
    return chickenCounter;
}

void ChickenMatrixGame::setChickenCounter(int value)
{
    chickenCounter = value;
}

void ChickenMatrixGame::clear()
{
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){

            scene->removeItem(matrix[i][j]);
            matrix[i][j] = nullptr;
        }
    }
}
