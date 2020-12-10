#include "headers/usernamewindow.h"
#include "ui_usernamewindow.h"

void UsernameWindow::onOk()
{
    if(mw->getReachedLevel() == 1)
        m_ready = true;
    else
        m_levelChooseReady = true;
    delete this;
}

void UsernameWindow::onSkip()
{
    m_ready = true;
    delete this;
}

void UsernameWindow::onCancel()
{
    delete this;
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

UsernameWindow::UsernameWindow(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::UsernameWindow),
    m_ready(false),
    mw(parent)
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

bool UsernameWindow::ready() const
{
    return m_ready;
}

bool UsernameWindow::levelChooseReady()
{
    return m_levelChooseReady;
}

void UsernameWindow::setReady(bool value)
{
    m_ready = value;
}
