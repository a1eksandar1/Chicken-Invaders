#ifndef QUITGAMEWINDOW_H
#define QUITGAMEWINDOW_H

#include <QDialog>

#include "headers/maingamewindow.h"

namespace Ui {
class QuitGameWindow;
}

class QuitGameWindow : public QDialog
{
    Q_OBJECT

public slots:
    void onOk();
    void onCancel();
    void onEscFromMGW();

protected:
    void keyPressEvent(QKeyEvent *event) override;

public:
    explicit QuitGameWindow(MainGameWindow *parent = nullptr);
    ~QuitGameWindow();

private:
    Ui::QuitGameWindow *ui;
    MainGameWindow *mgw;
};

#endif // QUITGAMEWINDOW_H
