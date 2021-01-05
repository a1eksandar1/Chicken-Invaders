#include "headers/enemies_h/wavechicken.h"

WaveChicken::WaveChicken(MainWindow *parent, QTimer* cleanTimer, int m, int n) :
    m(m), n(n), cleanTimer(cleanTimer), mw(parent)
{
    if(mw->isHard())
        this->shotCounter = 2;
    else if(!mw->isHard())
        this->shotCounter = 1;

    this->width = mw->getWidth();
    this->height = mw->getHeight();

    setPixmap(QPixmap(":images/chicken/pinkchicken.png").scaled(width/13, height/9, Qt::KeepAspectRatio));

    setPos(width/13*m + 20, -height/9*(n+1));
}

WaveChicken::~WaveChicken()
{

}

void WaveChicken::die()
{
    if (canBeshot)
        shotCounter--;
    if (!shot and shotCounter == 0 and canBeshot)
    {
        shot = true;
        emit waveChickenDied();
        setPixmap(QPixmap(":images/chicken/shot_chicken.png").scaled(width/12, height/9, Qt::KeepAspectRatio));
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

void WaveChicken::clean()
{
    scene()->removeItem(this);
    delete this;
}

void WaveChicken::advance(int step)
{
    if (!step)
    {
        return;
    }

    if (!mw->getFreezeScene())
    {
        if(imgChange == 0)
            setPixmap(QPixmap(":images/chicken/pinkchicken.png").scaled(width/13, height/9, Qt::KeepAspectRatio));
        if(imgChange == 1)
            setPixmap(QPixmap(":images/chicken/pinkchicken2.png").scaled(width/13, height/9, Qt::KeepAspectRatio));
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

        setPos(pos().x(), pos().y()+orientation);

        if (pos().y() > height/3-height/13)
        {
            canBeshot = true;
        }

        if (pos().y() >height/3)
        {
            orientation = -orientation;
            wave = false;
        }

        if (!wave and pos().y() < 10)
            orientation = -orientation;

        if (pos().y() > height or pos().x() > width)
            die();
    }
}
