#include "headers/planetchickengame.h"
#include <QGraphicsScene>
#include <algorithm>
#include <vector>



PlanetChickenGame::PlanetChickenGame(MainWindow *parent, QGraphicsScene *scene,int num, int pl):
     mw(parent),scene(scene), num(num), pl(pl), chickenCounter(num)
{

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    this->width = width;
    this->height = height;

    if(pl ==1)
    {
        planet = new QGraphicsPixmapItem();
        planet->setPixmap(QPixmap(":images/chicken/earth.png").scaled(150,150,Qt::KeepAspectRatio));
        planet->setPos((width-180)/2,(height-180)/2);
        scene->addItem(planet);
    }
    else if(pl == 2)
    {
        planet = new QGraphicsPixmapItem();
        planet->setPixmap(QPixmap(":images/chicken/uranus.png").scaled(150,150,Qt::KeepAspectRatio));
        planet->setPos((width-180)/2,(height-180)/2);
        scene->addItem(planet);
    }

    matrix.resize(num);
    for (int i = 0; i < num; i++)
    {
        matrix[i] = new PlanetChicken(mw, i, i);

    }

}


PlanetChickenGame::~PlanetChickenGame()
{

}


void PlanetChickenGame::start()
{
    for (int i=0; i < num ; i++)
    {
        scene->addItem(matrix[i]);

        connect(matrix[i], &PlanetChicken::planetChickenDied, this, &PlanetChickenGame::onChickenDeath);

    }

}

void PlanetChickenGame::onChickenDeath()
{
    chickenCounter = chickenCounter - 1;
    if(chickenCounter == 0)
    {
        clear();
        emit closePlanetChickenGame();
    }
}

int PlanetChickenGame::getChickenCounter() const
{
    return chickenCounter;
}

void PlanetChickenGame::setChickenCounter(int value)
{
    chickenCounter = value;
}

void PlanetChickenGame::clear()
{
    scene->removeItem(planet);

    for(int i = 0; i < num; i++){

            matrix[i] = nullptr;

    }

    matrix.clear();

}
