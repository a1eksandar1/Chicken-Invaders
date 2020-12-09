#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include "spaceship.h"
#include <QDialog>
#include "headers/mainwindow.h"

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

public:
    MainWindow *mw;

private:
    Ui::GameWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    Spaceship* spaceship;
};

#endif // GAMEWINDOW_H
