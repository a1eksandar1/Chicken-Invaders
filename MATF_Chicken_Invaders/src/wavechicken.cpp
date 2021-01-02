#include "headers/wavechicken.h"
#include <QTimer>
#include <QList>
#include "headers/egg.h"
#include "headers/gift.h"
#include <QDebug>
#include <QScreen>
#include <QApplication>
#include "headers/drumstick.h"


WaveChicken::WaveChicken(MainWindow *parent, int m, int n) :
    m(m), n(n), mw(parent)
{

    setPixmap(QPixmap(":images/chicken/pinkchicken.png").scaled(100,100,Qt::KeepAspectRatio));
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    this->width = width;
    this->height = height;
    this->color = rand()%3;

    setPos(120*m + 20, -100*(n+1));



}

WaveChicken::~WaveChicken()
{

}


int WaveChicken::getOrientation() const
{
    return orientation;
}

void WaveChicken::setOrientation(int value)
{
    orientation = value;
}

bool WaveChicken::getShot() const
{
    return shot;
}

void WaveChicken::setShot(bool value)
{
    shot = value;
}

void WaveChicken::die()
{
    if(!shot)
    {
        shot = true;
        emit waveChickenDied();
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

void WaveChicken::clean()
{
    scene()->removeItem(this);
    delete this;
}

int WaveChicken::getImgChange() const
{
    return imgChange;
}

void WaveChicken::setImgChange(int value)
{
    imgChange = value;
}

void WaveChicken::advance(int step)
{
    if (!step)
    {
        return;
    }


    if(imgChange == 0)
        setPixmap(QPixmap(":images/chicken/pinkchicken.png").scaled(120,120,Qt::KeepAspectRatio));
    if(imgChange == 1)
        setPixmap(QPixmap(":images/chicken/pinkchicken2.png").scaled(120,120,Qt::KeepAspectRatio));
    if(imgChange == 3)
        return;

    imgChange = (imgChange + 1)%2;


    int random_number1 = rand() % 300;
    int random_number2 = rand() % 1000;

    if (random_number1 == 5)
    {
        Egg *egg = new Egg(mw);
        egg->setPos(pos().x(),pos().y()+100);
        scene()->addItem(egg);

    }

    if (random_number2 == 5)
    {
        Gift * gift = new Gift(mw);
        gift->setPos(pos().x(),pos().y()+100);
        scene()->addItem(gift);

    }



    setPos(pos().x(),pos().y()+orientation);

    if(pos().y() > height/2)
    {
        orientation = -orientation;
        isEgg = false;
    }
    if(!isEgg and pos().y() < 10)
        orientation = -orientation;



    if(pos().y() > height)
        die();



}
