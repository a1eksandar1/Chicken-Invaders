#include "headers/gamewindow.h"
#include "headers/chicken.h"
#include "ui_gamewindow.h"
#include <QDialog>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
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
        close();
        music->stop();
        mw->playMusic();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

GameWindow::GameWindow(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow),
    scene(new QGraphicsScene(this)),
    music(new QMediaPlayer),
    mw(parent),
    timer(new QTimer(this))

{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    music->setMedia(QUrl("qrc:/sounds/sounds/MainTheme1.mp3"));
    music->setVolume(mw->getVolume());
    music->play();
    scene->setSceneRect(0, 0, width-30, height-30);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::start()
{   
    auto spaceship = new Spaceship();
    scene->addItem(spaceship);

//    Chicken* chicken = new Chicken(1,1);
//    scene->addItem(chicken);
//    Chicken* chicken2 = new Chicken(3,1);
//    scene->addItem(chicken2);
//    Chicken* chicken3 = new Chicken(7,1);
//    scene->addItem(chicken3);
//    Chicken* chicken4 = new Chicken(5,1);
//    scene->addItem(chicken4);

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


    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(200);



}
