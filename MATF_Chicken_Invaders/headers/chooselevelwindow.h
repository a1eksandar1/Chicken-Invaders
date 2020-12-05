#ifndef CHOOSELEVELWINDOW_H
#define CHOOSELEVELWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QtCore>
#include <QtGui>
#include "headers/mainwindow.h"
#include <QMediaPlayer>
#include "headers/chicken.h"
#include "headers/sidespaceship.h"
#include <QGraphicsSceneMouseEvent>
#include "headers/planet.h"

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

    void addElementsOnScene();
    void connects();
};

#endif // CHOOSELEVELWINDOW_H
