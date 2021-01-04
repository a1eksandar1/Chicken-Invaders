#ifndef CHOOSELEVELWINDOW_H
#define CHOOSELEVELWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QtCore>
#include <QtGui>
#include "headers/main_h/mainwindow.h"
#include <QMediaPlayer>
#include "headers/enemies_h/chicken.h"
#include "headers/spaceship_h/sidespaceship.h"
#include <QGraphicsSceneMouseEvent>
#include "headers/main_h/planet.h"

namespace Ui {
class ChooseLevelWindow;
}

class ChooseLevelWindow : public QWidget
{
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void setGraphicsViewBackground();

public slots:
    void onPluto();
    void onNeptune();
    void onUranus();
    void onSaturn();
    void onJupiter();
    void onMars();
    void onEarth();
    void onVenus();
    void onMercury();
    void closeWindow();

public:
    explicit ChooseLevelWindow(MainWindow *parent = nullptr);
    ~ChooseLevelWindow();

    int getDesiredLevel() const;
    void setDesiredLevel(int value);

private:
    void addElementsOnScene();
    void connects();

private:
    Ui::ChooseLevelWindow *ui;
    QGraphicsScene *scene;
    MainWindow *mw;
    int desiredLevel;
    SideSpaceship *ship;
    QTimer *timer;
    Planet *pluto;
    Planet *neptune;
    Planet *uranus;
    Planet *saturn;
    Planet *jupiter;
    Planet *mars;
    Planet *earth;
    Planet *venus;
    Planet *mercury;
    qreal height;
    qreal width;
    QGraphicsEllipseItem *ellipse;
};

#endif // CHOOSELEVELWINDOW_H
