#include <QApplication>
#include <QDesktopWidget>
#include <QSplashScreen>
#include <QTimer>

#include "headers/main_h/mainwindow.h"

int main(int argc, char *argv[])
{
      QApplication a(argc, argv);
      MainWindow w;

      a.setWindowIcon(QIcon(":/images/backgrounds/matf_chicken.ico"));

      QSplashScreen *splash = new QSplashScreen;
      splash->setPixmap(QPixmap(":/images/backgrounds/splash.png"));
      splash->show();

      w.setWindowState(Qt::WindowFullScreen);
      QTimer::singleShot(2000, splash, SLOT(close()));
      QTimer::singleShot(2000, &w, SLOT(show()));

      return a.exec();
}
