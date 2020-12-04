#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QPalette>
#include <QPainter>
#include <QApplication>
#include <QList>
#include <QDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include <QMessageBox>
#include <QtGui>
#include <QPushButton>
#include <QDebug>
#include <QHBoxLayout>
#include "headers/usernamewindow.h"
#include <iostream>
#include "headers/gamewindow.h"
#include "headers/optionswindow.h"
#include <QMediaPlayer>
#include "headers/chooselevelwindow.h"

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QPixmap bkgnd(":images/backgrounds/level1.png");

    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    QMainWindow::resizeEvent(event);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        close();
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}

void MainWindow::onQuit()
{
    close();
}

void MainWindow::onPlay()
{
    UsernameWindow* uw = new UsernameWindow(this);
    uw->setWindowFlags(Qt::CustomizeWindowHint);
    uw->setAttribute(Qt::WA_TranslucentBackground);
    uw->exec();

    if(uw->ready()){
        GameWindow* gw = new GameWindow(this);
        gw->start();

        gw->setWindowFlags(Qt::Window);
        gw->showFullScreen();

        music->stop();
    }
    else if(uw->levelChooseReady()){
        ChooseLevelWindow* lw = new ChooseLevelWindow(this);
        lw->setWindowFlags(Qt::Window);
        lw->showFullScreen();
    }
}

void MainWindow::onOptions()
{
    OptionsWindow* ow = new OptionsWindow(this);
    ow->setWindowState(Qt::WindowFullScreen);
    ow->exec();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    hard(false),
    music(new QMediaPlayer),
    volume(100),
    userCurrentLevel(1)
{
    ui->setupUi(this);

    music->setMedia(QUrl("qrc:/sounds/sounds/MainTheme2.mp3"));
    music->play();

    connect(ui->quit_button, &QPushButton::clicked, this, &MainWindow::onQuit);
    connect(ui->play_button, &QPushButton::clicked, this, &MainWindow::onPlay);
    connect(ui->options_button, &QPushButton::clicked, this, &MainWindow::onOptions);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isHard()
{
    return hard;
}

void MainWindow::setHard(bool h)
{
    hard = h;
}

void MainWindow::playMusic()
{
    music->play();
}

void MainWindow::setVolume(int volume)
{
    this->volume = volume;
    music->setVolume(volume);
}

int MainWindow::getVolume()
{
    return volume;
}

int MainWindow::getUserCurrentLevel()
{
    return userCurrentLevel;
}

void MainWindow::setUserCurrentLevel(int level)
{
    userCurrentLevel = level;
}
