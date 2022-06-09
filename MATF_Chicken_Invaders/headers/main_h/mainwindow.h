#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <headers/main_h/player.h>
#include <headers/main_h/score.h>

#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QPainter>
#include <QPalette>
#include <QPushButton>
#include <QSqlDatabase>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui
{
      class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
      Q_OBJECT

     protected:
      void resizeEvent(QResizeEvent* event) override;

     signals:
      void changeScore(int step);

     public slots:
      void onQuit();
      void onPlay();
      void onOptions();
      void onHof();

     public:
      MainWindow(QWidget* parent = nullptr);
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
      void setScore(int value);
      void connectToDatabase();

      bool getFreezeScene() const;
      void setFreezeScene(bool value);
      Score* getScore();
      int width, height;

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
      QMediaPlayer* drumstickSound;
      QSqlDatabase mydb;
      Player* active_player;
      QMediaPlayer* victorySound;
      int getProjectilesLevel() const;
      void setProjectilesLevel(int value);

      int getWidth() const;
      void setWidth(int value);

      int getHeight() const;
      void setHeight(int value);

     private:
      Ui::MainWindow* ui;
      bool hard;
      int volume;
      int desiredLevel;
      int reachedLevel;
      bool planetClicked;
      bool freezeScene;
      Score* score;
      int projectilesLevel;
};
#endif  // MAINWINDOW_H
