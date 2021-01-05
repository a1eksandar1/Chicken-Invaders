#include "headers/games_h/meteorshowergame.h"
#include <QGraphicsScene>

MeteorShowerGame::MeteorShowerGame(MainWindow *parent, QGraphicsScene *scene,int m, int n):
    mw(parent),scene(scene), m(m), n(n), meteorCounter(m*n)
{
    this->moveMeteorTimer = new QTimer(this);
    this->cleanMeteorTimer = new QTimer(this);

    matrix.resize(m);

    for (int i=0; i < m; i++)
    {
        matrix[i].resize(n);
    }

    for (int i=0; i < m ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = new Meteor(mw,moveMeteorTimer, cleanMeteorTimer, i, j, 1);
        }
    }
}

MeteorShowerGame::~MeteorShowerGame()
{

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

void MeteorShowerGame::clear()
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            matrix[i][j] = nullptr;
        }
        matrix[i].clear();
    }
    matrix.clear();
}
