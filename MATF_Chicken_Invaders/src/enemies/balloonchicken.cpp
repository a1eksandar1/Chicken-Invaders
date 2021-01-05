#include "headers/enemies_h/balloonchicken.h"

BalloonChicken::BalloonChicken(MainWindow *parent, QTimer* cleanTimer, int m, int n, int num1, int num2) :
    m(m), n(n), num1(num1), num2(num2), cleanTimer(cleanTimer), mw(parent)
{
    if(mw->isHard())
        this->shotCounter = 5;
    else if(!mw->isHard())
        this->shotCounter = 3;

    this->width = mw->getWidth();
    this->height = mw->getHeight();

    setPixmap(QPixmap(":images/chicken/balloonChicken3.png").scaled(width/13, height/9, Qt::KeepAspectRatio));
    setPos(width/13*m + 30, -height/8*(num2-n));

}
BalloonChicken::~BalloonChicken()
{

}

void BalloonChicken::die()
{
    shotCounter--;
    if (balloonCounter > 0)
        balloonCounter--;

    if (balloonCounter == 2)
        setPixmap(QPixmap(":images/chicken/balloonChicken2.png").scaled(width/13, height/9, Qt::KeepAspectRatio));
    if(balloonCounter == 1)
        setPixmap(QPixmap(":images/chicken/balloonChicken1.png").scaled(width/13, height/9, Qt::KeepAspectRatio));
    else if (balloonCounter == 0 and !shot and shotCounter == 0)
    {
        shot = true;
        emit balloonChickenDied();
        setPixmap(QPixmap(":images/chicken/shot_chicken.png").scaled(width/13, height/9, Qt::KeepAspectRatio));
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

void BalloonChicken::clean()
{
    scene()->removeItem(this);
    delete this;
}

void BalloonChicken::advance(int step)
{
    if (!step)
    {
        return;
    }

    if(!mw->getFreezeScene())
    {
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

        if (pos().x() + width/13*(num1-1-m) > width - width/13)
            orientation = -10;

        if (pos().x() - width/13*(m) < 0)
            orientation = 10;

        if (pos().y() < height/7*n)
            setPos(pos().x()+orientation, pos().y()+10);
        else
            setPos(pos().x()+orientation, pos().y());
    }
}
