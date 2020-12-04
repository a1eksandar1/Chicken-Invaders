#ifndef CHOOSELEVELWINDOW_H
#define CHOOSELEVELWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QtCore>
#include <QtGui>
#include "headers/mainwindow.h"
#include <QMediaPlayer>

namespace Ui {
class ChooseLevelWindow;
}

class ChooseLevelWindow : public QWidget
{
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void setGraphicsViewBackground();

public:
    explicit ChooseLevelWindow(MainWindow *parent = nullptr);
    ~ChooseLevelWindow();

private:
    Ui::ChooseLevelWindow *ui;
    QGraphicsScene *scene;
    MainWindow *mw;
};

#endif // CHOOSELEVELWINDOW_H
