#include "headers/enemies_h/chicken.h"

Chicken::Chicken(MainWindow *parent, QTimer* cleanTimer, int m, int n, int num1, int num2) :
   m(m), n(n), num1(num1), num2(num2), cleanTimer(cleanTimer), mw(parent)
{
    if (mw->isHard())
        this->shotCounter = 2;
    else if (!mw->isHard())
        this->shotCounter = 1;

    this->width = mw->getWidth();
    this->height = mw->getHeight();

    setPixmap(QPixmap(":images/chicken/matf_chicken1.png").scaled(width/13, height/7, Qt::KeepAspectRatio));
    setPos(width/13*m + 30, -height/7*(num2-n) - 20);
}

Chicken::~Chicken()
{
}

void Chicken::die()
{
    shotCounter--;
    if (!shot and shotCounter == 0)
    {
        shot = true;
        emit chickenDied();
        setPixmap(QPixmap(":images/chicken/shot_chicken.png").scaled(120, 120, Qt::KeepAspectRatio));
        imgChange = 3;

        mw->chickenSound->stop();
        mw->chickenSound->play();
        mw->chickenSound->setVolume(mw->getVolume() == 0 ? 0 : 100);

        Drumstick *drumstick = new Drumstick(mw);
        drumstick->setPos(pos().x(), pos().y()+100);
        scene()->addItem(drumstick);

        connect(cleanTimer, SIGNAL(timeout()), this, SLOT(clean()));
        cleanTimer->start(200);
    }
}

void Chicken::clean()
{
    scene()->removeItem(this);
    delete this;
}

void Chicken::advance(int step)
{
    if (!step)
    {
        return;
    }

    if (!mw->getFreezeScene()){

        if(imgChange == 0)
            setPixmap(QPixmap(":images/chicken/matf_chicken1.png").scaled(120, 120, Qt::KeepAspectRatio));
        if(imgChange == 1)
            setPixmap(QPixmap(":images/chicken/matf_chicken2.png").scaled(120, 120, Qt::KeepAspectRatio));
        if(imgChange == 3)
            return;

        imgChange = (imgChange + 1)%2;

        int random_number1 = rand() % 300;
        int random_number2 = rand() % 1000;

        if (random_number1 == 5)
        {
            Egg *egg = new Egg(mw);
            egg->setPos(pos().x(), pos().y()+100);
            scene()->addItem(egg);
        }

        if (random_number2 == 5)
        {
            Gift * gift = new Gift(mw);
            gift->setPos(pos().x(), pos().y()+100);
            scene()->addItem(gift);

        }

        if(pos().x() + width/13*(num1-1-m) > width - width/13)
            orientation = -10;

        if(pos().x() - width/13*(m) < 0)
            orientation = 10;

        if(pos().y() < height/7*n + 10)
            setPos(pos().x()+orientation, pos().y()+10);
        else
            setPos(pos().x()+orientation, pos().y());
    }
}
