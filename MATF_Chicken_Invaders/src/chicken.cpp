#include "headers/chicken.h"
#include <QTimer>
#include <QList>
#include "headers/egg.h"
#include "headers/gift.h"
#include <QDebug>
#include <QScreen>
#include <QApplication>
#include "headers/drumstick.h"
Chicken::Chicken(MainWindow *parent, int m, int n, int num1, int num2) :
    num1(num1), num2(num2), mw(parent)
{
    this->m = m;
    this->n = n;

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    this->width = width;
    this->height = height;

    setPixmap(QPixmap(":images/chicken/matf_chicken1.png").scaled(height/7,height/7,Qt::KeepAspectRatio));
    setPos(width/11*m + 20, -height/7*(num2-n) - 10);

}

Chicken::~Chicken()
{

}



int Chicken::getOrientation() const
{
    return orientation;
}

void Chicken::setOrientation(int value)
{
    orientation = value;
}

bool Chicken::getShot() const
{
    return shot;
}

void Chicken::setShot(bool value)
{
    shot = value;
}

void Chicken::die()
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

void Chicken::clean()
{
    scene()->removeItem(this);
    delete this;
}

int Chicken::getImgChange() const
{
    return imgChange;
}

void Chicken::setImgChange(int value)
{
    imgChange = value;
}

void Chicken::advance(int step)
{
    if (!step)
    {
        return;
    }

    if(!mw->getFreezeScene()){

        if(imgChange == 0)
            setPixmap(QPixmap(":images/chicken/matf_chicken1.png").scaled(120,120,Qt::KeepAspectRatio));
        if(imgChange == 1)
            setPixmap(QPixmap(":images/chicken/matf_chicken2.png").scaled(120,120,Qt::KeepAspectRatio));
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

        if(pos().x() + width/11*(num1-1-m) > width - width/11)
            orientation = -10;

        if(pos().x() - width/11*(m) < 0)
            orientation = 10;

        if(pos().y() < height/7*n + 10)
            setPos(pos().x()+orientation,pos().y()+10);
        else
            setPos(pos().x()+orientation,pos().y());
    }
}
