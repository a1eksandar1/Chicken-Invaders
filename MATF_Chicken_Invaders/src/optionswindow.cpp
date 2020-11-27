#include "headers/optionswindow.h"
#include "ui_optionswindow.h"
#include "headers/mainwindow.h"

void OptionsWindow::resizeEvent(QResizeEvent *event)
{
    QPixmap bkgnd(":images/backgrounds/optionsWindowBackground.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    QDialog::resizeEvent(event);
}

OptionsWindow::OptionsWindow(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::OptionsWindow),
    mw(parent)
{
    ui->setupUi(this);

    ui->easyButton->setChecked(!parent->isHard());
    ui->hardButton->setChecked(parent->isHard());

    connect(ui->backButton, &QPushButton::clicked, this, &OptionsWindow::onBack);
}

OptionsWindow::~OptionsWindow()
{
    delete ui;
}

void OptionsWindow::onBack()
{
    if(ui->hardButton->isChecked())
        mw->setHard(true);
    else
        mw->setHard(false);

    close();
}
