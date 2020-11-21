#include "headers/gamewindow.h"
#include "ui_gamewindow.h"
#include <QDialog>
#include <QKeyEvent>

void GameWindow::keyPressEvent(QKeyEvent *event)
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

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::start()
{

}
