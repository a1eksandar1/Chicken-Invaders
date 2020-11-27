#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void onQuit();
    void onPlay();
    void onOptions();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool isHard();
    void setHard(bool h);

private:
    Ui::MainWindow *ui;
    bool hard;
};
#endif // MAINWINDOW_H
