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

protected:
    void keyPressEvent(QKeyEvent *event) override;

public:
    explicit MainGameWindow(MainWindow *parent = nullptr);
    ~MainGameWindow();

private:
    const int width = 1280;
    const int height = 720;
    Ui::MainGameWindow *ui;
    MainWindow *mw;
    AnimatedGraphicsItem *background;
    QGraphicsScene *scene;
    QScrollBar *scroll;
    QPropertyAnimation *animation;
    int fly_speed;
    Spaceship *spaceship;
};

#endif // MAINGAMEWINDOW_H
