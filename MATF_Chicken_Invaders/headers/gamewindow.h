#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;


public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    void start();

private:
    Ui::GameWindow *ui;
    QGraphicsScene *scene;
};

#endif // GAMEWINDOW_H
