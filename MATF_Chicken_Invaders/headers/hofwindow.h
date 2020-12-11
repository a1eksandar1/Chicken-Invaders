#ifndef HOFWINDOW_H
#define HOFWINDOW_H

#include "headers/mainwindow.h"

#include <QDialog>

namespace Ui {
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

private:
    Ui::HofWindow *ui;
    MainWindow* mw;
};

#endif // HOFWINDOW_H
