#include "headers/meteorshowergame.h"
#include <QGraphicsScene>

MeteorShowerGame::MeteorShowerGame(MainWindow *parent, QGraphicsScene *scene,int m, int n):
    mw(parent),scene(scene), m(m), n(n), meteorCounter(m*n)
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
                matrix[i][j] = new Meteor(mw,i,j,1);
            }
        }


}

MeteorShowerGame::~MeteorShowerGame()
{

}

QVector<QVector<Meteor *> > MeteorShowerGame::getMatrix() const
{
    return matrix;
}

void MeteorShowerGame::start()
{
    for (int i=0; i < m ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scene->addItem(matrix[i][j]);
            connect(matrix[i][j], &Meteor::meteorShot, this, &MeteorShowerGame::onMeteorShot);
        }
    }

}

void MeteorShowerGame::onMeteorShot()
{
    meteorCounter =  meteorCounter - 1;
    if(meteorCounter == 0)
    {
        clear();
        emit closeMeteorShowerGame();
    }

}

int MeteorShowerGame::getMeteorCounter() const
{
    return meteorCounter;
}

void MeteorShowerGame::setMeteorCounter(int value)
{
    meteorCounter = value;
}


void MeteorShowerGame::clear()
{
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = nullptr;
        }
        matrix[i].clear();
    }
    matrix.clear();
}
