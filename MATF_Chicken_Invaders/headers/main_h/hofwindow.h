#ifndef HOFWINDOW_H
#define HOFWINDOW_H

#include <QDialog>
#include <QFileInfo>
#include <QtDebug>
#include <QtSql>

#include "headers/main_h/mainwindow.h"
#include "headers/main_h/player.h"

namespace Ui
{
      class HofWindow;
}

class HofWindow : public QDialog
{
      Q_OBJECT

     protected:
      void resizeEvent(QResizeEvent *) override;

     public:
      explicit HofWindow(MainWindow *parent = nullptr);
      ~HofWindow();

      void onBack();
      void LoadData();
      void insertPlayer(Player player);

     private:
      Ui::HofWindow *ui;
      MainWindow *mw;
      //    QSqlDatabase mydb;
};

#endif  // HOFWINDOW_H
