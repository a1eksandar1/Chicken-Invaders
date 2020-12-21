#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <headers/score.h>
#include <headers/lives.h>

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
    void playBackgroundMusic();
    void setVolume(int volume);
    int getVolume() const;
    int getUserCurrentLevel() const;
    void setUserCurrentLevel(int level);
    int getDesiredLevel() const;
    void setDesiredLevel(int value);
    int getReachedLevel() const;
    void setReachedLevel(int value);
    void openGameWindow();
    void closeGameWindow();
    void setBackGroundMusic(QString str);
    void stopBackGroundMusic();
    bool getPlanetClicked() const;
    void setPlanetClicked(bool value);
    Score* getScore();
    void increaseScore();
    Lives* getLives();

private:
    void setMusic();
    void setConnects();

public:
    QMediaPlayer* backGroundMusic;
    QMediaPlayer* projectileSound;
    QMediaPlayer* giftSound;
    QMediaPlayer* chickenSound;
    QMediaPlayer* eggSound;
    QMediaPlayer* explosionSound;
    QMediaPlayer* gameOverSound;
    QMediaPlayer* gamePrepareSound;

private:
    Ui::MainWindow *ui;
    bool hard;
    int volume;
    int userCurrentLevel;
    int desiredLevel;
    int reachedLevel;
    bool planetClicked;
    Score* score;
    Lives* lives;


};
#endif // MAINWINDOW_H
