#include "headers/gamewindow.h"
#include "ui_gamewindow.h"
#include <QDialog>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
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
    mw(parent)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    music->setMedia(QUrl("qrc:/sounds/sounds/MainTheme1.mp3"));
    music->setVolume(mw->getVolume());
    music->play();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::start()
{
    auto spaceship = new Spaceship();
    scene->addItem(spaceship);
}
