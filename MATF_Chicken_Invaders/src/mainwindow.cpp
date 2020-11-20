#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QPalette>
#include <QPainter>
#include <QApplication>
#include <QList>
#include <QDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include <QMessageBox>
#include <QtGui>
#include <QPushButton>
#include <QDebug>
#include <QHBoxLayout>
#include "headers/usernamewindow.h"
#include "ui_usernamewindow.h"
#include <headers/mainwindow.h>

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QPixmap bkgnd(":images/backgrounds/level1.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    QMainWindow::resizeEvent(event);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        close();
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}

void MainWindow::onQuit()
{
    close();
}

void MainWindow::onPlay()
{
    UsernameWindow uw;
    uw.exec();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ui1(new Ui::UsernameWindow)
{
    ui->setupUi(this);

    connect(ui->quit_button, &QPushButton::clicked, this, &MainWindow::onQuit);
    connect(ui->play_button, &QPushButton::clicked, this, &MainWindow::onPlay);

}

MainWindow::~MainWindow()
{
    delete ui;
}

