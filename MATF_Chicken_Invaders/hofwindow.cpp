#include "hofwindow.h"
#include "ui_hofwindow.h"

HofWindow::HofWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HofWindow)
{
    ui->setupUi(this);
}

HofWindow::~HofWindow()
{
    delete ui;
}
