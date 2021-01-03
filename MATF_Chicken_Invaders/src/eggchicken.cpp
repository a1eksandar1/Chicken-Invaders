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
    if(mw->isHard())
        this->shotCounter = 3;
    else if(!mw->isHard())
        this->shotCounter = 2;

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    this->width = width;
    this->height = height;

    setPixmap(QPixmap(":images/chicken/egg_1.png").scaled(width/14,height/10,Qt::KeepAspectRatio));

    this->color = rand()%3;

    setPos(width/10*m + 20, -height/9*(n+1));


}

EggChicken::~EggChicken()
{

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
    shotCounter--;
    if(isEgg and (pos().y() >height or pos().x() > width) and !shot)
    {
        shot = true;
        emit eggChickenDied();
        clean();
    }
    else if(isEgg)
        isEgg = false;
    else if(!isEgg and !shot and shotCounter == 0)
    {
        shot = true;
        emit eggChickenDied();
        setPixmap(QPixmap(":images/chicken/shot_chicken.png").scaled(width/14,height/10,Qt::KeepAspectRatio));
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
                    setPixmap(QPixmap(":images/chicken/greenchicken.png").scaled(width/12,height/10,Qt::KeepAspectRatio));
                if(imgChange == 1)
                    setPixmap(QPixmap(":images/chicken/greenchicken2.png").scaled(width/12,height/10,Qt::KeepAspectRatio));
                if(imgChange == 3)
                    return;

                imgChange = (imgChange + 1)%2;
            }
            else if(color == 1)
            {
                if(imgChange == 0)
                    setPixmap(QPixmap(":images/chicken/bluechicken.png").scaled(width/12,height/10,Qt::KeepAspectRatio));
                if(imgChange == 1)
                    setPixmap(QPixmap(":images/chicken/bluechicken2.png").scaled(width/12,height/10,Qt::KeepAspectRatio));
                if(imgChange == 3)
                    return;

                imgChange = (imgChange + 1)%2;
            }
            else if(color == 2)
            {
                if(imgChange == 0)
                    setPixmap(QPixmap(":images/chicken/pinkchicken.png").scaled(width/12,height/10,Qt::KeepAspectRatio));
                if(imgChange == 1)
                    setPixmap(QPixmap(":images/chicken/pinkchicken2.png").scaled(width/12,height/10,Qt::KeepAspectRatio));
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
                setPos(pos().x(),pos().y()+yOrientation);
        }
        else
        {
            setPos(pos().x()+xOrientation,pos().y()+yOrientation);
            xOrientation = -xOrientation;
        }

        if(pos().y() > height)
            die();
    }
}
