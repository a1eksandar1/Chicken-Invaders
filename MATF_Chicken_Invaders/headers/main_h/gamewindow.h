#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QDialog>
#include "headers/main_h/mainwindow.h"
#include "headers/spaceship_h/spaceship.h"


namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent * event) override;

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
    QTimer* throwingBulletsTimer;

public slots:
    void kraj();
};

#endif // GAMEWINDOW_H
