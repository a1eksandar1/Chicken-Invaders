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

#include "headers/spaceship.h"
#include "headers/mainwindow.h"

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

public slots:
    void slow_down();
    void removeMessage();
    void igra1PomocnaFunkcija();
    void stopPrepareMusic();
    void playPrepareMusic();

protected:
    void keyPressEvent(QKeyEvent *event) override;

public:
    explicit MainGameWindow(MainWindow *parent = nullptr);
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

private:
    int width;
    int height;
    Ui::MainGameWindow *ui;
    MainWindow *mw;
    AnimatedGraphicsItem *background;
    QGraphicsScene *scene;
    QScrollBar *scroll;
    QPropertyAnimation *animation;
    int fly_speed;
    Spaceship *spaceship;
    QTimer *timer;
    QGraphicsPixmapItem *message;
};

#endif // MAINGAMEWINDOW_H
