#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include "spaceship.h"
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "headers/mainwindow.h"
#include <QMediaPlayer>

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;

public:
    explicit GameWindow(MainWindow *parent = nullptr);
    ~GameWindow();

    void start();

private:
    Ui::GameWindow *ui;
    QGraphicsScene *scene;
    QMediaPlayer *music;
    MainWindow *mw;
    QTimer *timer;
    Spaceship* spaceship;
};

#endif // GAMEWINDOW_H
