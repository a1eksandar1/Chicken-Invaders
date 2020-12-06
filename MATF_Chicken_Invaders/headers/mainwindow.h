#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>

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
    void onHof();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool isHard();
    void setHard(bool h);
    void playMusic();
    void setVolume(int volume);
    int getVolume();
    int getUserCurrentLevel();
    void setUserCurrentLevel(int level);

private:
    Ui::MainWindow *ui;
    bool hard;
    QMediaPlayer* music;
    int volume;
    int userCurrentLevel;
};
#endif // MAINWINDOW_H
