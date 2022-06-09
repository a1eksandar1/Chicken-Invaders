#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QDialog>
#include <QSlider>

#include "headers/main_h/mainwindow.h"

namespace Ui
{
      class OptionsWindow;
}

class OptionsWindow : public QDialog
{
      Q_OBJECT

     public slots:
      void volumeChanged();

     protected:
      void resizeEvent(QResizeEvent *) override;

     public:
      explicit OptionsWindow(MainWindow *parent = nullptr);
      ~OptionsWindow();

      void onBack();

     private:
      Ui::OptionsWindow *ui;
      MainWindow *mw;
};

#endif  // OPTIONSWINDOW_H
