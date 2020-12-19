#include "headers/gamewindow.h"
#include "headers/chicken.h"
#include "headers/projectile.h"
#include "ui_gamewindow.h"
#include <QDialog>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QScreen>
#include <QTimer>

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        for(size_t i=0, n = scene->items().size(); i<n; i++)
        {
            scene->items()[i]->setEnabled(false);
        }
        scene->clear();
        mw->backGroundMusic->stop();
        mw->backGroundMusic->setMedia(QUrl("qrc:/sounds/sounds/MainTheme2.mp3"));
        mw->backGroundMusic->play();
        delete this;
        break;
    case Qt::Key_Space:
        if(spaceship->getThrowingAllowed()){
            spaceship->setThrowingAllowed(false);
            spaceship->throw_projectile();
        }
        break;
    case Qt::Key_A: // change it to be LeftArrow
        spaceship->move_left();
        break;
    case Qt::Key_D: // change it to be RightArrow
        spaceship->move_right();
        break;
    case Qt::Key_W: // change it to be UpArrow
        spaceship->move_up();
        break;
    case Qt::Key_S: // change it to be DownArrow
        spaceship->move_down();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

GameWindow::GameWindow(MainWindow *parent) :
    mw(parent),
    ui(new Ui::GameWindow),
    scene(new QGraphicsScene(this)),
    timer(new QTimer(this)),
    spaceship(new Spaceship(mw))
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    mw->backGroundMusic->stop();
    mw->backGroundMusic->setMedia(QUrl("qrc:/sounds/sounds/MainTheme.mp3"));
    mw->backGroundMusic->play();

    scene->setSceneRect(0, 0, width-30, height-30);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::start()
{
    QRect rec = QApplication::primaryScreen()->geometry();
    int height = rec.height();
    int width = rec.width();

    spaceship->setStartingPosition(width/2-65, height-120);

    spaceship->setPos(spaceship->getStartingXPos(), spaceship->getStartingYPos());
    scene->addItem(spaceship);

    QVector<QVector<Chicken*>> chick;
    chick.resize(8);
    for (int i=0; i < 8; i++)
    {
        chick[i].resize(3);
    }

    for (int i=0; i < 8 ; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            chick[i][j] = new Chicken(mw,i,j);
            scene->addItem(chick[i][j]);
        }
    }
    //testiranje
//    Meteor *meteor1 = new Meteor(mw,1,1);
//    scene->addItem(meteor1);

//    Meteor *meteor2 = new Meteor(mw,2,3);
//    scene->addItem(meteor2);

    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);
}
