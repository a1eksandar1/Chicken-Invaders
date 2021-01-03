#include "headers/planetchicken.h"
#include <QTimer>
#include <QList>
#include "headers/egg.h"
#include "headers/gift.h"
#include <QDebug>
#include <QScreen>
#include <QApplication>
#include "headers/drumstick.h"


PlanetChicken::PlanetChicken(MainWindow *parent, int m, int n) :
    m(m), n(n), mw(parent)
{

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    this->width = width;
    this->height = height;
    setPixmap(QPixmap(":images/chicken/matf_chicken1.png").scaled(width/12,height/9,Qt::KeepAspectRatio));

    setPos((width)/2+130, -height/9*(n+1) + 50);


}

PlanetChicken::~PlanetChicken()
{

}


int PlanetChicken::getOrientation() const
{
    return orientation;
}

void PlanetChicken::setOrientation(int value)
{
    orientation = value;
}

bool PlanetChicken::getShot() const
{
    return shot;
}

void PlanetChicken::setShot(bool value)
{
    shot = value;
}

void PlanetChicken::die()
{
    if(!shot)
    {
        shot = true;
        emit planetChickenDied();
        setPixmap(QPixmap(":images/chicken/shot_chicken.png").scaled(120,120,Qt::KeepAspectRatio));
        imgChange=3;

        mw->chickenSound->stop();
        mw->chickenSound->play();
        mw->chickenSound->setVolume(mw->getVolume() == 0 ? 0 : 100);

        Drumstick *drumstick = new Drumstick(mw);
        drumstick->setPos(pos().x(),pos().y()+100);
        scene()->addItem(drumstick);


        QTimer *cleanTimer = new QTimer(this);
        connect(cleanTimer, SIGNAL(timeout()), this, SLOT(clean()));
        cleanTimer->start(200);
    }
}

void PlanetChicken::clean()
{
    scene()->removeItem(this);
    delete this;
}

int PlanetChicken::getImgChange() const
{
    return imgChange;
}

void PlanetChicken::setImgChange(int value)
{
    imgChange = value;
}

void PlanetChicken::advance(int step)
{
    if (!step)
    {
        return;
    }


    if(!mw->getFreezeScene()){
        if(imgChange == 0)
            setPixmap(QPixmap(":images/chicken/matf_chicken1.png").scaled(width/12,height/9,Qt::KeepAspectRatio));
        if(imgChange == 1)
            setPixmap(QPixmap(":images/chicken/matf_chicken2.png").scaled(width/12,height/9,Qt::KeepAspectRatio));
        if(imgChange == 3)
            return;

        imgChange = (imgChange + 1)%2;


        int random_number1 = rand() % 6;
        int random_number2 = rand() % 1000;

        if (random_number1 % 2 == 0 and !rotate)
        {
            Egg *egg = new Egg(mw);
            egg->setPos(pos().x()+20,pos().y()+100);
            scene()->addItem(egg);

        }
        if(random_number1 == 5)
        {
            Egg *egg = new Egg(mw);
            egg->setPos(pos().x()+20,pos().y()+100);
            scene()->addItem(egg);

        }

        if (random_number2 == 5)
        {
            Gift * gift = new Gift(mw);
            gift->setPos(pos().x(),pos().y()+100);
            scene()->addItem(gift);

        }

        if(pos().y()> height/2-250)
            rotate = true;

        if(!rotate)
        {
            setPos(pos().x(),pos().y()+orientation);
        }
        else if(rotate)
        {
            double x = cos(t)*scale;
            double y = sin(t)*scale;
            setPos(width/2-75+x, height/2-230+y);
            t += 0.1;
        }

        if(pos().y() > height)
            die();
    }
}
