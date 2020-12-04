#include "headers/chooselevelwindow.h"
#include "ui_chooselevelwindow.h"
#include <iostream>
#include <QDesktopWidget>

void ChooseLevelWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        close();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void ChooseLevelWindow::setGraphicsViewBackground()
{
    QRect rec = QApplication::primaryScreen()->geometry();
    int height = rec.height();
    int width = rec.width();

    QPixmap bkgnd(":images/backgrounds/level1.png");

    if(mw->getUserCurrentLevel() == 2){
        QPixmap bkgnd_pom(":images/backgrounds/level2.png");
        bkgnd = bkgnd_pom;
    }
    else if(mw->getUserCurrentLevel() == 3){
        QPixmap bkgnd_pom(":images/backgrounds/level3.png");
        bkgnd = bkgnd_pom;
    }
    else if(mw->getUserCurrentLevel() == 4){
        QPixmap bkgnd_pom(":images/backgrounds/level4.png");
        bkgnd = bkgnd_pom;
    }
    else if(mw->getUserCurrentLevel() == 5){
        QPixmap bkgnd_pom(":images/backgrounds/level5.png");
        bkgnd = bkgnd_pom;
    }
    else if(mw->getUserCurrentLevel() == 6){
        QPixmap bkgnd_pom(":images/backgrounds/level6.png");
        bkgnd = bkgnd_pom;
    }
    else if(mw->getUserCurrentLevel() == 7){
        QPixmap bkgnd_pom(":images/backgrounds/level7.png");
        bkgnd = bkgnd_pom;
    }
    else if(mw->getUserCurrentLevel() == 8){
        QPixmap bkgnd_pom(":images/backgrounds/level8.png");
        bkgnd = bkgnd_pom;
    }
    else if(mw->getUserCurrentLevel() == 9){
        QPixmap bkgnd_pom(":images/backgrounds/level9.png");
        bkgnd = bkgnd_pom;
    }

    bkgnd = bkgnd.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(ui->graphicsView->backgroundRole(),bkgnd);
    ui->graphicsView->setPalette(palette);
}

ChooseLevelWindow::ChooseLevelWindow(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::ChooseLevelWindow),
    mw(parent)
{
    ui->setupUi(this);

    setGraphicsViewBackground();

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

ChooseLevelWindow::~ChooseLevelWindow()
{
    delete ui;
}
