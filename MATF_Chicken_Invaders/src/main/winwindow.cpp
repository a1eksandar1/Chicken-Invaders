#include "headers/main_h/winwindow.h"

#include "ui_winwindow.h"

void winWindow::onQuit()
{
      mw->onQuit();
      delete this;
}

void winWindow::onBack()
{
      mw->victorySound->stop();
      mw->backGroundMusic->play();
      mw->setReachedLevel(1);
      mw->setProjectilesLevel(1);
      delete this;
}

void winWindow::resizeEvent(QResizeEvent *event)
{
      QPixmap bkgnd(":images/backgrounds/winWindowBackground.png");
      bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
      QPalette palette;
      palette.setBrush(QPalette::Window, bkgnd);
      this->setPalette(palette);

      QDialog::resizeEvent(event);
}

winWindow::winWindow(MainWindow *parent) : QDialog(parent), ui(new Ui::winWindow), mw(parent)
{
      ui->setupUi(this);

      connect(ui->quitButton, &QPushButton::clicked, this, &winWindow::onQuit);
      connect(ui->backButton, &QPushButton::clicked, this, &winWindow::onBack);
}

winWindow::~winWindow() { delete ui; }
