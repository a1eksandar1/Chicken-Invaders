#include "headers/usernamewindow.h"
#include "ui_usernamewindow.h"


void UsernameWindow::onOk()
{
    m_ready = true;
    close();
}

void UsernameWindow::onSkip()
{
    m_ready = true;
    close();
}

void UsernameWindow::onCancel()
{
    close();
}

void UsernameWindow::resizeEvent(QResizeEvent *event)
{
    QPixmap bkgnd(":images/backgrounds/usernameWindow.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);


    QDialog::resizeEvent(event);
}

UsernameWindow::UsernameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsernameWindow),
    m_ready(false)
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

bool UsernameWindow::ready()
{
    return m_ready;
}
