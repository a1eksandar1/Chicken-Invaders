#include "headers/hofwindow.h"
#include "ui_hofwindow.h"
#include "headers/mainwindow.h"

void HofWindow::resizeEvent(QResizeEvent *event)
{
    QPixmap bkgnd(":images/backgrounds/optionsWindowBackground.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    QDialog::resizeEvent(event);
}

HofWindow::HofWindow(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::HofWindow),
    mw(parent)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &HofWindow::onBack);
}

HofWindow::~HofWindow()
{
    delete ui;

}



void HofWindow::onBack()
{
    close();
}
