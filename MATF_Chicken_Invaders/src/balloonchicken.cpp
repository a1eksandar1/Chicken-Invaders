#include "headers/balloonchicken.h"
#include <QTimer>
#include <QList>
#include "headers/egg.h"
#include "headers/gift.h"
#include <QDebug>
#include <QScreen>
#include <QApplication>
#include "headers/drumstick.h"

BalloonChicken::BalloonChicken(MainWindow *parent, int m, int n, int num) :
    mw(parent)
{

    this->m = m;
    this->n = n;
    setPixmap(QPixmap(":images/chicken/balloonChicken3.png").scaled(170,150,Qt::KeepAspectRatio));

    setPos(150*m + 20, -170*(num-n));

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    this->width = width;
    this->height = height;


}

BalloonChicken::~BalloonChicken()
{

}



int BalloonChicken::getOrientation() const
{
    return orientation;
}

void BalloonChicken::setOrientation(int value)
{
    orientation = value;
}

bool BalloonChicken::getShot() const
{
    return shot;
}

void BalloonChicken::setShot(bool value)
{
    shot = value;
}

void BalloonChicken::die()
{
    balloonCounter--;
    if(balloonCounter == 2)
        setPixmap(QPixmap(":images/chicken/balloonChicken2.png").scaled(170,150,Qt::KeepAspectRatio));
    if(balloonCounter == 1)
        setPixmap(QPixmap(":images/chicken/balloonChicken1.png").scaled(170,150,Qt::KeepAspectRatio));
    else if(balloonCounter == 0 and !shot)
    {
        shot = true;
        emit balloonChickenDied();
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

void BalloonChicken::clean()
{
    scene()->removeItem(this);
    delete this;
}

int BalloonChicken::getImgChange() const
{
    return imgChange;
}

void BalloonChicken::setImgChange(int value)
{
    imgChange = value;
}

void BalloonChicken::advance(int step)
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

        if(pos().x() + 150*(7-m) > width - 150)
            orientation = -10;

        if(pos().x() - 150*(m) < 0)
            orientation = 10;

        if(pos().y() < 170*n)
            setPos(pos().x()+orientation,pos().y()+10);
        else
            setPos(pos().x()+orientation,pos().y());

    }
}
