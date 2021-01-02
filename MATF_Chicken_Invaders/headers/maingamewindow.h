#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QAbstractAnimation>
#include <QScrollBar>
#include <QPropertyAnimation>
#include <QTimer>

#include "headers/sidemeteorshowergame.h"
#include "headers/chickenmatrixgame.h"
#include "headers/meteorshowergame.h"
#include "headers/bossgame.h"
#include "headers/balloongame.h"
#include "headers/sideChickenGame.h"
#include "headers/spaceship.h"
#include "headers/mainwindow.h"
#include "headers/gamewindow.h"

class View;
class AnimatedGraphicsItem : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
};

namespace Ui {
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
    void stopPrepareMusic();
    void playPrepareMusic();
    void setUserMessage();
    void endOfGame();
    void continueGame();
    void victory();
    void increaseScore(int step);
    void updatePlayer();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent * event) override;

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

public:
    MainWindow *mw;
    QPropertyAnimation *animation;

private:
    Ui::MainGameWindow *ui;
    int width;
    int height;
    AnimatedGraphicsItem *background;
    QGraphicsScene *scene;
    QScrollBar *scroll;
    int fly_speed;
    Spaceship *spaceship;
    QTimer *timer;
    QGraphicsPixmapItem *message;
    int waveCounter;
    GameWindow *qgw;
    bool openedQuitWindow;
};

#endif // MAINGAMEWINDOW_H
