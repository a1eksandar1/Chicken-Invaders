#include "headers/gamewindow.h"
#include "ui_gamewindow.h"
#include <QDialog>

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
