#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QAbstractAnimation>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QLineEdit>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QRadioButton>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QScrollBar>
#include <QTimer>
#include <QWidget>

#include "headers/games_h/balloongame.h"
#include "headers/games_h/bossgame.h"
#include "headers/games_h/chickenmatrixgame.h"
#include "headers/games_h/eggchickengame.h"
#include "headers/games_h/meteorshowergame.h"
#include "headers/games_h/planetchickengame.h"
#include "headers/games_h/sideChickenGame.h"
#include "headers/games_h/sidemeteorshowergame.h"
#include "headers/games_h/wavechickengame.h"
#include "headers/main_h/mainwindow.h"
#include "headers/spaceship_h/spaceship.h"

class View;
class AnimatedGraphicsItem : public QObject, public QGraphicsPixmapItem
{
      Q_OBJECT
      Q_PROPERTY(QPointF pos READ pos WRITE setPos)
};

namespace Ui
{
      class MainGameWindow;
}

class MainGameWindow : public QWidget
{
      Q_OBJECT

     signals:
      void gameStart();
      void esc();

     public slots:
      void removeMessage();
      void slot_level1();
      void slot_level2();
      void slot_level3();
      void slot_level4();
      void slot_level5();
      void slot_level6();
      void slot_level7();
      void slot_level8();
      void slot_level9();
      void stopPrepareMusic();
      void playPrepareMusic();
      void setUserMessage();
      void endOfGame();
      void continueGame();
      void victory();
      void increaseScore(int step);
      void updatePlayer(int current_high_score);
      void updateLives();
      void showChangedScore();

     protected:
      void keyPressEvent(QKeyEvent *event) override;
      void keyReleaseEvent(QKeyEvent *event) override;

     public:
      MainGameWindow(MainWindow *parent = nullptr);
      ~MainGameWindow();

      int getFly_speed() const;
      void setFly_speed(int value);
      void level1();
      void level2();
      void level3();
      void level4();
      void level5();
      void level6();
      void level7();
      void level8();
      void level9();
      void start();
      void openQuitGameWindow();
      void bigEggGame(int health);
      int current_high_score;

     public:
      MainWindow *mw;
      QPropertyAnimation *animation;
      QGraphicsScene *scene;

     private:
      Ui::MainGameWindow *ui;
      int width;
      int height;
      AnimatedGraphicsItem *background;

      QScrollBar *scroll;
      int fly_speed;
      Spaceship *spaceship;
      QTimer *timer;
      QGraphicsPixmapItem *message;
      int waveCounter;
      bool openedQuitWindow;
      QGraphicsPixmapItem *lives;
      Score *score;
      bool updateable;
};

#endif  // MAINGAMEWINDOW_H
