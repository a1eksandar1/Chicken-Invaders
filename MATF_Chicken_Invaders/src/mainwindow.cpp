#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

#include "headers/usernamewindow.h"
#include "headers/gamewindow.h"
#include "headers/optionswindow.h"
#include "headers/chooselevelwindow.h"
#include "headers/maingamewindow.h"
#include "headers/quitgamewindow.h"

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
        openGameWindow();
        uw->setReady(false);
    }
    else if(uw->levelChooseReady()){
        openChooseLevelWindow();
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
    score(0),
    ui(new Ui::MainWindow),
    hard(false),
    volume(20),
    desiredLevel(1),
    reachedLevel(2),
    planetClicked(false),
    freezeScene(false)
{
    ui->setupUi(this);
    setMusic();
    setConnects();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isHard() const
{
    return hard;
}

void MainWindow::setHard(bool h)
{
    hard = h;
}

void MainWindow::playBackgroundMusic()
{
    backGroundMusic->play();
}

void MainWindow::setVolume(int volume)
{
    this->volume = volume;
    backGroundMusic->setVolume(volume);
    gameOverSound->setVolume(volume);
    eggSound->setVolume(volume);
    explosionSound->setVolume(volume);
    giftSound->setVolume(volume);
}

int MainWindow::getVolume() const
{
    return volume;
}

int MainWindow::getDesiredLevel() const
{
    return desiredLevel;
}

void MainWindow::setDesiredLevel(int value)
{
    desiredLevel = value;
}

int MainWindow::getReachedLevel() const
{
    return reachedLevel;
}

void MainWindow::setReachedLevel(int value)
{
    reachedLevel = value;
}

void MainWindow::openGameWindow()
{
    MainGameWindow* mgw = new MainGameWindow(this);
    //mgw->start();

    mgw->setWindowFlags(Qt::Window);
    mgw->showFullScreen();
}

void MainWindow::openChooseLevelWindow()
{
    planetClicked = false;
    ChooseLevelWindow* lw = new ChooseLevelWindow(this);

    lw->setWindowFlags(Qt::Window);
    lw->showFullScreen();
}

void MainWindow::setBackGroundMusic(QString str)
{
    backGroundMusic->setMedia(QUrl(str));
}

void MainWindow::stopBackGroundMusic()
{
    backGroundMusic->stop();
}

bool MainWindow::getPlanetClicked() const
{
    return planetClicked;
}

void MainWindow::setPlanetClicked(bool value)
{
    planetClicked = value;
}

void MainWindow::pauseAllSounds()
{
    backGroundMusic->pause();
    projectileSound->pause();
    eggSound->pause();
    explosionSound->pause();
    chickenSound->pause();
    giftSound->pause();
    gameOverSound->pause();
    gamePrepareSound->pause();
    victorySound->pause();
}

void MainWindow::setMusic()
{
    backGroundMusic = new QMediaPlayer;
    projectileSound = new QMediaPlayer;
    eggSound = new QMediaPlayer;
    explosionSound = new QMediaPlayer;
    chickenSound = new QMediaPlayer;
    giftSound = new QMediaPlayer;
    gameOverSound = new QMediaPlayer;
    gamePrepareSound = new QMediaPlayer;
    victorySound = new QMediaPlayer;

    backGroundMusic->setMedia(QUrl("qrc:/sounds/sounds/MainTheme.mp3"));
    chickenSound->setMedia(QUrl("qrc:/sounds/sounds/ShotChicken.mp3"));
    giftSound->setMedia(QUrl("qrc:/sounds/sounds/GiftSound.mp3"));
    projectileSound->setMedia(QUrl("qrc:/sounds/sounds/Projectile.mp3"));
    eggSound->setMedia(QUrl("qrc:/sounds/sounds/Egg.mp3"));
    explosionSound->setMedia(QUrl("qrc:/sounds/sounds/SpaceshipExplosion.mp3"));
    gameOverSound->setMedia(QUrl("qrc:/sounds/sounds/GameOver.mp3"));
    gamePrepareSound->setMedia(QUrl("qrc:/sounds/sounds/prepare.mp3"));
    victorySound->setMedia(QUrl("qrc:/sounds/sounds/Victory.mp3"));

    backGroundMusic->setVolume(volume);
    chickenSound->setVolume(volume);
    gameOverSound->setVolume(volume);
    eggSound->setVolume(volume);
    explosionSound->setVolume(volume);
    giftSound->setVolume(volume);
    projectileSound->setVolume(volume);
    gamePrepareSound->setVolume(volume);
    victorySound->setVolume(volume);

    backGroundMusic->play();
}

void MainWindow::setConnects()
{
    connect(ui->quit_button, &QPushButton::clicked, this, &MainWindow::onQuit);
    connect(ui->play_button, &QPushButton::clicked, this, &MainWindow::onPlay);
    connect(ui->options_button, &QPushButton::clicked, this, &MainWindow::onOptions);
}

bool MainWindow::getFreezeScene() const
{
    return freezeScene;
}

void MainWindow::setFreezeScene(bool value)
{
    freezeScene = value;
}

int MainWindow::getScore() const
{
    return score;
}

void MainWindow::setScore(int value)
{
    score = value;
}
