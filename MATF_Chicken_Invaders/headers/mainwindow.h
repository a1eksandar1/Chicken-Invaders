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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool isHard() const;
    void setHard(bool h);
    void playMusic();
    void setVolume(int volume);
    int getVolume() const;
    int getUserCurrentLevel() const;
    void setUserCurrentLevel(int level);
    int getDesiredLevel() const;
    void setDesiredLevel(int value);
    int getReachedLevel() const;
    void setReachedLevel(int value);
    void openGameWindow();

private:
    Ui::MainWindow *ui;
    bool hard;
    QMediaPlayer* music;
    int volume;
    int userCurrentLevel;
    int desiredLevel;
    int reachedLevel;
};
#endif // MAINWINDOW_H
