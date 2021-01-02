#include "headers/eggchicken.h"
#include <QTimer>
#include <QList>
#include "headers/egg.h"
#include "headers/gift.h"
#include <QDebug>
#include <QScreen>
#include <QApplication>
#include "headers/drumstick.h"


EggChicken::EggChicken(MainWindow *parent, int m, int n) :
    m(m), n(n), mw(parent)
{

    setPixmap(QPixmap(":images/chicken/egg_1.png").scaled(100,100,Qt::KeepAspectRatio));

    this->color = rand()%3;

    setPos(120*m + 20, -100*(n+1));

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    this->width = width;
    this->height = height;


}

EggChicken::~EggChicken()
{

}


int EggChicken::getOrientation() const
{
    return orientation;
}

void EggChicken::setOrientation(int value)
{
    orientation = value;
}

bool EggChicken::getShot() const
{
    return shot;
}

void EggChicken::setShot(bool value)
{
    shot = value;
}

void EggChicken::die()
{
    if(isEgg)
        isEgg = false;

    else if(!isEgg and !shot)
    {
        shot = true;
        emit eggChickenDied();
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

void EggChicken::clean()
{
    scene()->removeItem(this);
    delete this;
}

int EggChicken::getImgChange() const
{
    return imgChange;
}

void EggChicken::setImgChange(int value)
{
    imgChange = value;
}

void EggChicken::advance(int step)
{
    if (!step)
    {
        return;
    }

    if(!mw->getFreezeScene()){
        if(!isEgg)
        {
            if(color == 0)
            {
                if(imgChange == 0)
                    setPixmap(QPixmap(":images/chicken/greenchicken.png").scaled(120,120,Qt::KeepAspectRatio));
                if(imgChange == 1)
                    setPixmap(QPixmap(":images/chicken/greenchicken2.png").scaled(120,120,Qt::KeepAspectRatio));
                if(imgChange == 3)
                    return;

                imgChange = (imgChange + 1)%2;
            }
            else if(color == 1)
            {
                if(imgChange == 0)
                    setPixmap(QPixmap(":images/chicken/bluechicken.png").scaled(120,120,Qt::KeepAspectRatio));
                if(imgChange == 1)
                    setPixmap(QPixmap(":images/chicken/bluechicken2.png").scaled(120,120,Qt::KeepAspectRatio));
                if(imgChange == 3)
                    return;

                imgChange = (imgChange + 1)%2;
            }
            else if(color == 2)
            {
                if(imgChange == 0)
                    setPixmap(QPixmap(":images/chicken/pinkchicken.png").scaled(120,120,Qt::KeepAspectRatio));
                if(imgChange == 1)
                    setPixmap(QPixmap(":images/chicken/pinkchicken2.png").scaled(120,120,Qt::KeepAspectRatio));
                if(imgChange == 3)
                    return;

                imgChange = (imgChange + 1)%2;
            }
        }

        int random_number1 = rand() % 300;
        int random_number2 = rand() % 1000;
        if (random_number1 == 5 and !isEgg)
        {
            Egg *egg = new Egg(mw);
            egg->setPos(pos().x(),pos().y()+100);
            scene()->addItem(egg);

        }

        if (random_number2 == 5 and !isEgg)
        {
            Gift * gift = new Gift(mw);
            gift->setPos(pos().x(),pos().y()+100);
            scene()->addItem(gift);

        }


        if(isEgg)
        {
                setPos(pos().x(),pos().y()+20);
        }
        else
        {
            setPos(pos().x()+orientation,pos().y()+20);
            orientation = -orientation;
        }

        if(pos().y() > height)
            die();
    }
}
