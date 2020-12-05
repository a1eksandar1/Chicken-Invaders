#include "headers/chooselevelwindow.h"
#include "ui_chooselevelwindow.h"
#include <iostream>
#include <QDesktopWidget>
#include <QDebug>

void ChooseLevelWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        close();
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
    ship->setBoundary(width/150);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(30);
}

void ChooseLevelWindow::onNeptune()
{
    ship->setBoundary(width/12.5);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(25);
}

void ChooseLevelWindow::onUranus()
{
    ship->setBoundary(width/5.1);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(25);
}

void ChooseLevelWindow::onSaturn()
{
    ship->setBoundary(width/2.95);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(20);
}

void ChooseLevelWindow::onJupiter()
{
    ship->setBoundary(width/2.1);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(20);
}

void ChooseLevelWindow::onMars()
{
    ship->setBoundary(width/1.635);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(15);
}

void ChooseLevelWindow::onEarth()
{
    ship->setBoundary(width/1.45);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(15);
}

void ChooseLevelWindow::onVenus()
{
    ship->setBoundary(width/1.241);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(10);
}

void ChooseLevelWindow::onMercury()
{

    ship->setBoundary(width/1.08);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(10);
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
    pluto = new Planet(mw,width/60,height - height/4,65,65, "Pluto");
    neptune = new Planet(mw,width/12.5,height - height/3.5,150,150, "Neptune");
    uranus = new Planet(mw,width/5.1,height - height/3.5,140,140, "Uranus");
    saturn = new Planet(mw,width/2.95,height - height/3.5,140,140, "Saturn");
    jupiter = new Planet(mw,width/2.1,height - height/3.3,200,200, "Jupiter");
    mars = new Planet(mw, width/1.635,height - height/3.9,80,80, "Mars");
    earth = new Planet(mw,width/1.45,height - height/3.68,140,140,"Earth");
    venus = new Planet(mw, width/1.241,height - height/3.68,140,140, "Venus");
    mercury = new Planet(mw,width/1.08,height - height/4.2,90,90,"Mercury");

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
