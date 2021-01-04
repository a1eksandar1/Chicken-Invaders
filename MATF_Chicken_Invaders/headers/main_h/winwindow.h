#ifndef WINWINDOW_H
#define WINWINDOW_H

#include <QDialog>
#include "headers/main_h/mainwindow.h"

namespace Ui {
class winWindow;
}

class winWindow : public QDialog
{
    Q_OBJECT

protected:
    void resizeEvent(QResizeEvent *event) override;

public slots:
    void onQuit();
    void onBack();

public:
    explicit winWindow(MainWindow *parent = nullptr);
    ~winWindow();

private:
    Ui::winWindow *ui;
    MainWindow *mw;
};

#endif // WINWINDOW_H
