#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QDesktopWidget>
#include <QPalette>
#include <QPainter>
#include <QKeyEvent>
#include <QtGui>
#include <QPushButton>
#include <QDebug>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void onQuit();
    void onPlay();
    void onOptions();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void pauseAllSounds();
    bool isHard() const;
    void setHard(bool h);
    void playBackgroundMusic();
    void setVolume(int volume);
    int getVolume() const;
    int getDesiredLevel() const;
    void setDesiredLevel(int value);
    int getReachedLevel() const;
    void setReachedLevel(int value);
    void openGameWindow();
    void openChooseLevelWindow();
    void closeGameWindow();
    void setBackGroundMusic(QString str);
    void stopBackGroundMusic();
    bool getPlanetClicked() const;
    void setPlanetClicked(bool value);    
    int getScore() const;
    void setScore(int value);
    bool getFreezeScene() const;
    void setFreezeScene(bool value);

private:
    void setMusic();
    void setConnects();

public:
    QMediaPlayer* backGroundMusic;
    QMediaPlayer* projectileSound;
    QMediaPlayer* giftSound;
    QMediaPlayer* chickenSound;
    QMediaPlayer* eggSound;
    QMediaPlayer* explosionSound;
    QMediaPlayer* gameOverSound;
    QMediaPlayer* gamePrepareSound;
    QMediaPlayer* victorySound;
    int score;

private:
    Ui::MainWindow *ui;
    bool hard;
    int volume;
    int desiredLevel;
    int reachedLevel;
    bool planetClicked;
    bool freezeScene;

};
#endif // MAINWINDOW_H
