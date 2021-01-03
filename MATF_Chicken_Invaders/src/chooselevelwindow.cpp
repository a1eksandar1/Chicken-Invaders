#include "headers/chooselevelwindow.h"
#include "ui_chooselevelwindow.h"
#include <QDesktopWidget>
#include <QDebug>
#include <QGraphicsPixmapItem>

void ChooseLevelWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        mw->setDesiredLevel(1);
        mw->setReachedLevel(1);
        mw->setProjectilesLevel(1);
        delete this;
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void ChooseLevelWindow::setGraphicsViewBackground()
{
    QRect rec = QApplication::primaryScreen()->geometry();
    int height = rec.height();
    int width = rec.width();

    QPixmap bkgnd(":images/backgrounds/level1.png");

    if(mw->getReachedLevel() == 2){
        QPixmap bkgnd_pom(":images/backgrounds/level2.png");
        bkgnd = bkgnd_pom;
    }
    else if(mw->getReachedLevel() == 3){
        QPixmap bkgnd_pom(":images/backgrounds/level3.png");
        bkgnd = bkgnd_pom;
    }
    else if(mw->getReachedLevel() == 4){
        QPixmap bkgnd_pom(":images/backgrounds/level4.png");
        bkgnd = bkgnd_pom;
    }
    else if(mw->getReachedLevel() == 5){
        QPixmap bkgnd_pom(":images/backgrounds/level5.png");
        bkgnd = bkgnd_pom;
    }
    else if(mw->getReachedLevel() == 6){
        QPixmap bkgnd_pom(":images/backgrounds/level6.png");
        bkgnd = bkgnd_pom;
    }
    else if(mw->getReachedLevel() == 7){
        QPixmap bkgnd_pom(":images/backgrounds/level7.png");
        bkgnd = bkgnd_pom;
    }
    else if(mw->getReachedLevel() == 8){
        QPixmap bkgnd_pom(":images/backgrounds/level8.png");
        bkgnd = bkgnd_pom;
    }
    else if(mw->getReachedLevel() == 9){
        QPixmap bkgnd_pom(":images/backgrounds/level9.png");
        bkgnd = bkgnd_pom;
    }

    bkgnd = bkgnd.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(ui->graphicsView->backgroundRole(),bkgnd);
    ui->graphicsView->setPalette(palette);
}

void ChooseLevelWindow::onPluto()
{
    ship->setBoundary_x(width/150);
    ship->setBoundary_y(height - height/4);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(10);
    mw->setDesiredLevel(1);
}

void ChooseLevelWindow::onNeptune()
{
    ship->setBoundary_x(width/12.5);
    ship->setBoundary_y(height - height/3.5);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(10);
    mw->setDesiredLevel(2);
}

void ChooseLevelWindow::onUranus()
{
    ship->setBoundary_x(width/5.1);
    ship->setBoundary_y(height - height/3.4);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(10);
    mw->setDesiredLevel(3);
}

void ChooseLevelWindow::onSaturn()
{
    ship->setBoundary_x(width/2.95);
    ship->setBoundary_y(height - height/3.4);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(10);
    mw->setDesiredLevel(4);
}

void ChooseLevelWindow::onJupiter()
{
    ship->setBoundary_x(width/2.1);
    ship->setBoundary_y(height - height/3.2);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(9);
    mw->setDesiredLevel(5);
}

void ChooseLevelWindow::onMars()
{
    ship->setBoundary_x(width/1.635);
    ship->setBoundary_y(height - height/3.9);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(9);
    mw->setDesiredLevel(6);
}

void ChooseLevelWindow::onEarth()
{
    ship->setBoundary_x(width/1.45);
    ship->setBoundary_y(height - height/3.5);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(9);
    mw->setDesiredLevel(7);
}

void ChooseLevelWindow::onVenus()
{
    ship->setBoundary_x(width/1.241);
    ship->setBoundary_y(height - height/3.68);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(9);
    mw->setDesiredLevel(8);
}

void ChooseLevelWindow::onMercury()
{
    ship->setBoundary_x(width/1.08);
    ship->setBoundary_y(height - height/4.1);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(9);
    mw->setDesiredLevel(9);
}

void ChooseLevelWindow::closeWindow()
{
    mw->openGameWindow();
    close();
}

ChooseLevelWindow::ChooseLevelWindow(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::ChooseLevelWindow),
    mw(parent),
    desiredLevel(0),
    ship(new SideSpaceship(parent)),
    timer(new QTimer(this))
{
    ui->setupUi(this);

    setGraphicsViewBackground();

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    scene->setSceneRect(0, 0, width-30, height-30);

    this->width = width;
    this->height = height;

    addElementsOnScene();

    QGraphicsPixmapItem *pm = scene->addPixmap(QPixmap(":images/backgrounds/choosethelevel.png").scaled(width,height));
    pm->setPos(0,0);

    connects();
}

ChooseLevelWindow::~ChooseLevelWindow()
{
    delete ui;
}

int ChooseLevelWindow::getDesiredLevel() const
{
    return desiredLevel;
}

void ChooseLevelWindow::setDesiredLevel(int value)
{
    desiredLevel = value;
}

void ChooseLevelWindow::addElementsOnScene()
{
    pluto = new Planet(mw,width/60,height - height/4,width/27,height/15, "Pluto");
    neptune = new Planet(mw,width/12.5,height - height/3.5,width/12,height/7, "Neptune");
    uranus = new Planet(mw,width/5.2,height - height/3.4,width/11,height/6.5, "Uranus");
    saturn = new Planet(mw,width/3,height - height/3.4,width/12,height/7, "Saturn");
    jupiter = new Planet(mw,width/2.15,height - height/3.2,width/8.6,height/4.7, "Jupiter");
    mars = new Planet(mw, width/1.67,height - height/3.9,width/18,height/10, "Mars");
    earth = new Planet(mw,width/1.47,height - height/3.5,width/12,height/7,"Earth");
    venus = new Planet(mw, width/1.25,height - height/3.68,width/12,height/7, "Venus");
    mercury = new Planet(mw,width/1.0847,height - height/4.1,width/19,height/10,"Mercury");

    scene->addItem(pluto);
    scene->addItem(neptune);
    scene->addItem(uranus);
    scene->addItem(saturn);
    scene->addItem(jupiter);
    scene->addItem(mars);
    scene->addItem(earth);
    scene->addItem(venus);
    scene->addItem(mercury);

    scene->addItem(ship);
}

void ChooseLevelWindow::connects()
{
    connect(pluto, &Planet::plutoClicked, this, &ChooseLevelWindow::onPluto);
    connect(neptune, &Planet::neptuneClicked, this, &ChooseLevelWindow::onNeptune);
    connect(uranus, &Planet::uranusClicked, this, &ChooseLevelWindow::onUranus);
    connect(saturn, &Planet::saturnClicked, this, &ChooseLevelWindow::onSaturn);
    connect(jupiter, &Planet::jupiterClicked, this, &ChooseLevelWindow::onJupiter);
    connect(mars, &Planet::marsClicked, this, &ChooseLevelWindow::onMars);
    connect(earth, &Planet::earthClicked, this, &ChooseLevelWindow::onEarth);
    connect(venus, &Planet::venusClicked, this, &ChooseLevelWindow::onVenus);
    connect(mercury, &Planet::mercuryClicked, this, &ChooseLevelWindow::onMercury);
    connect(ship, &SideSpaceship::sidespaceshipStop, this, &ChooseLevelWindow::closeWindow);
}
