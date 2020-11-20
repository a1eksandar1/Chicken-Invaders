#include "headers/usernamewindow.h"
#include "ui_usernamewindow.h"


void UsernameWindow::onOk()
{
    close();
}

void UsernameWindow::onSkip()
{
    close();
}

void UsernameWindow::onCancel()
{
    close();
}



UsernameWindow::UsernameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsernameWindow)
{
    ui->setupUi(this);
    connect(ui->cancelButton, &QPushButton::clicked, this, &UsernameWindow::onCancel);
    connect(ui->okButton, &QPushButton::clicked, this, &UsernameWindow::onOk);
    connect(ui->skipButton, &QPushButton::clicked, this, &UsernameWindow::onSkip);
}

UsernameWindow::~UsernameWindow()
{
    delete ui;
}



