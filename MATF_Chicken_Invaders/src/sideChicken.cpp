#include "headers/sideChicken.h"
#include <QTimer>
#include <QList>
#include "headers/egg.h"
#include "headers/gift.h"
#include <QDebug>
#include <QScreen>
#include <QApplication>
#include "headers/drumstick.h"

SideChicken::SideChicken(MainWindow *parent, int n) :
    mw(parent)
{
    this->n = n;
    setPixmap(QPixmap(":images/chicken/leftsideChicken.png").scaled(120,120,Qt::KeepAspectRatio));
    t = 4*n*3.14/36;
    scale = 2 / ( 3 - cos(2 * t)) * 600;

    setPos(width/2 + scale * cos(t), 200+ scale * sin(2 * t)/2);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    this->width = width;
    this->height = height;


}

SideChicken::~SideChicken()
{

}



int SideChicken::getOrientation() const
{
    return orientation;
}

void SideChicken::setOrientation(int value)
{
    orientation = value;
}

bool SideChicken::getShot() const
{
    return shot;
}

void SideChicken::setShot(bool value)
{
    shot = value;
}

void SideChicken::die()
{
    if(!shot)
    {
        shot = true;
        emit chickenDied();
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

void SideChicken::clean()
{
    scene()->removeItem(this);
    delete this;
}

int SideChicken::getImgChange() const
{
    return imgChange;
}

void SideChicken::setImgChange(int value)
{
    imgChange = value;
}

void SideChicken::advance(int step)
{
    if (!step)
    {
        return;
    }

    if(!mw->getFreezeScene()){
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


    //    if(pos().y() < 120*n + 10)
    //        setPos(pos().x()+orientation,pos().y()+10);
    //    else
    //        setPos(pos().x()+orientation,pos().y());
        if(t<=2*3.14)
        {
        if(t<=3.14)
        {
            if(imgChange == 0)
            setPixmap(QPixmap(":images/chicken/leftsideChicken.png").scaled(120,120,Qt::KeepAspectRatio));
            else if(imgChange == 1)
            setPixmap(QPixmap(":images/chicken/leftsideChicken2.png").scaled(120,120,Qt::KeepAspectRatio));


        }
        else
        {
            if(imgChange == 0)
            setPixmap(QPixmap(":images/chicken/rightsideChicken.png").scaled(120,120,Qt::KeepAspectRatio));
            else if(imgChange ==1)
                setPixmap(QPixmap(":images/chicken/rightsideChicken2.png").scaled(120,120,Qt::KeepAspectRatio));


        }
        if (imgChange == 3)
            return;

        imgChange = (imgChange + 1)%2;
        scale = 2 / ( 3 - cos(2 * t)) * 600;

        setPos(width/2 + scale * cos(t), 200+ scale * sin(2 * t)/2);
        t = t + 3.14/36;
        }
        else
        {
            t = 0;
            scale = 2 / ( 3 - cos(2 * t)) * 600;

            setPos(width/2 + scale * cos(t), 200+ scale * sin(2 * t)/2);
             t = t + 3.14/36;
        }
    }
}
