#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include "spaceship.h"
#include <QDialog>
#include <QtCore>
#include <QtGui>

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;


public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    void start();

private:
    Ui::GameWindow *ui;
    QGraphicsScene *scene;

//    QGraphicsEllipseItem *ellipse;
};

#endif // GAMEWINDOW_H
