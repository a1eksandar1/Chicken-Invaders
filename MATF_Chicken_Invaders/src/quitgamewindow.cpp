#include "headers/quitgamewindow.h"
#include "ui_quitgamewindow.h"
#include <QFocusEvent>

void QuitGameWindow::onOk()
{
    mgw->endOfGame();
    mgw->mw->setReachedLevel(1);
    mgw->mw->setFreezeScene(false);
    mgw->mw->setProjectilesLevel(1);
    delete this;
}

void QuitGameWindow::onCancel()
{
    mgw->mw->setFreezeScene(false);
    mgw->animation->start();
    delete this;
}

void QuitGameWindow::onEscFromMGW()
{
    delete this;
}

void QuitGameWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        mgw->mw->setFreezeScene(false);
        mgw->animation->start();
        delete this;
        break;
    default:
        QDialog::keyPressEvent(event);
    }
}

QuitGameWindow::QuitGameWindow(MainGameWindow *parent) :
    QDialog(parent),
    ui(new Ui::QuitGameWindow),
    mgw(parent)
{
    ui->setupUi(this);

    connect(ui->ok_button, &QPushButton::clicked, this, &QuitGameWindow::onOk);
    connect(ui->cancel_button, &QPushButton::clicked, this, &QuitGameWindow::onCancel);
    connect(mgw, &MainGameWindow::esc, this, &QuitGameWindow::onEscFromMGW);
}

QuitGameWindow::~QuitGameWindow()
{
    delete ui;
}
