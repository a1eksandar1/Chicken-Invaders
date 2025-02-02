#include "headers/main_h/maingamewindow.h"

#include <QFocusEvent>
#include <QGraphicsItem>
#include <QScreen>
#include <QSqlQuery>

#include "headers/enemies_h/bigegg.h"
#include "headers/enemies_h/bigeggbullets.h"
#include "headers/enemies_h/chicken.h"
#include "headers/main_h/quitgamewindow.h"
#include "headers/main_h/usernamewindow.h"
#include "headers/main_h/winwindow.h"
#include "ui_maingamewindow.h"

MainGameWindow::MainGameWindow(MainWindow *parent)
    : mw(parent),
      scene(new QGraphicsScene(this)),
      ui(new Ui::MainGameWindow),
      scroll(new QScrollBar),
      fly_speed(20000),
      spaceship(new Spaceship(mw)),
      timer(new QTimer(this)),
      message(new QGraphicsPixmapItem),
      waveCounter(0),
      openedQuitWindow(false),
      score(mw->getScore()),
      updateable(true)
{
      ui->setupUi(this);
      ui->graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
      ui->graphicsView->setScene(scene);

      QScreen *screen = QGuiApplication::primaryScreen();
      QRect screenGeometry = screen->geometry();
      height = screenGeometry.height();
      width = screenGeometry.width();

      scroll = ui->graphicsView->verticalScrollBar();

      QPixmap bkgnd(":/images/backgrounds/gameBackground.png");

      background = new AnimatedGraphicsItem;
      background->setPixmap(bkgnd.scaled(width, height * 3));

      animation = new QPropertyAnimation(background, "pos");
      animation->setLoopCount(-1);
      animation->setDuration(fly_speed);
      animation->setStartValue(QPoint(0, -2 * height));
      animation->setEndValue(QPoint(0, 0));
      animation->start();

      scene->addItem(background);
      scene->setFocus();
      scene->setSceneRect(0, 0, width - 30, height - 30);

      mw->backGroundMusic->stop();

      connect(spaceship, &Spaceship::spaceshipDestroyed, this, &MainGameWindow::endOfGame);
      connect(mw, &MainWindow::changeScore, this, &MainGameWindow::increaseScore);
      connect(mw, &MainWindow::changeScore, this, &MainGameWindow::showChangedScore);
      connect(spaceship, &Spaceship::spaceshipHited, this, &MainGameWindow::updateLives);

      mw->getScore()->setPos(pos().x() + 10, pos().y());
      scene->addItem(score);

      start();

      lives = new QGraphicsPixmapItem;
      if (mw->active_player->getLives() == 3)
      {
            QPixmap lv(":/images/spaceships/lives3.png");
            lives->setPixmap(lv);
            lives->setPos(width - 150, 0);
            scene->addItem(lives);
      }
      else if (mw->active_player->getLives() == 2)
      {
            QPixmap lv(":/images/spaceships/lives2.png");
            lives->setPixmap(lv);
            lives->setPos(width - 150, 0);
            scene->addItem(lives);
      }
      else if (mw->active_player->getLives() == 1)
      {
            QPixmap lv(":/images/spaceships/lives1.png");
            lives->setPixmap(lv);
            lives->setPos(width - 150, 0);
            scene->addItem(lives);
      }
}

void MainGameWindow::removeMessage()
{
      scene->removeItem(message);
      emit gameStart();
}

void MainGameWindow::slot_level1()
{
      if (waveCounter == 1)
      {
            ChickenMatrixGame *cmg = new ChickenMatrixGame(mw, scene, 9, 3);
            cmg->start();
            connect(cmg, &ChickenMatrixGame::closeChickenMatrixGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 2)
      {
            MeteorShowerGame *msg = new MeteorShowerGame(mw, scene, 8, 8);
            msg->start();
            connect(msg, &MeteorShowerGame::closeMeteorShowerGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 3)
      {
            BalloonGame *bg = new BalloonGame(mw, scene, 8, 3);
            bg->start();
            connect(bg, &BalloonGame::closeBalloonGame, this, &MainGameWindow::setUserMessage);
      }
}

void MainGameWindow::slot_level2()
{
      if (waveCounter == 1)
      {
            WaveChickenGame *wcg = new WaveChickenGame(mw, scene, 12, 1);
            wcg->start();
            connect(wcg, &WaveChickenGame::closeWaveChickenGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 2)
      {
            EggChickenGame *ecg = new EggChickenGame(mw, scene, 30);
            ecg->start();
            connect(ecg, &EggChickenGame::closeEggChickenGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 3)
      {
            if (!mw->isHard())
                  bigEggGame(50);
            else
                  bigEggGame(100);
      }
}

void MainGameWindow::slot_level3()
{
      if (waveCounter == 1)
      {
            SideChickenGame *scg = new SideChickenGame(mw, scene, 18);
            scg->start();
            connect(scg, &SideChickenGame::closeSideChickenGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 2)
      {
            sideMeteorShowerGame *smsg = new sideMeteorShowerGame(mw, scene, 7, 7);
            smsg->start();
            connect(smsg, &sideMeteorShowerGame::closeSideMeteorShowerGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 3)
      {
            PlanetChickenGame *pcg = new PlanetChickenGame(mw, scene, 12, 2);
            pcg->start();
            connect(pcg, &PlanetChickenGame::closePlanetChickenGame, this, &MainGameWindow::setUserMessage);
      }
}

void MainGameWindow::slot_level4()
{
      if (waveCounter == 1)
      {
            BalloonGame *bg = new BalloonGame(mw, scene, 9, 4);
            bg->start();
            connect(bg, &BalloonGame::closeBalloonGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 2)
      {
            EggChickenGame *ecg = new EggChickenGame(mw, scene, 30);
            ecg->start();
            connect(ecg, &EggChickenGame::closeEggChickenGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 3)
      {
            BossGame *bg = new BossGame(mw, scene, 75);
            bg->start();
            connect(bg, &BossGame::closeBossGame, this, &MainGameWindow::setUserMessage);
      }
}

void MainGameWindow::slot_level5()
{
      if (waveCounter == 1)
      {
            ChickenMatrixGame *cmg = new ChickenMatrixGame(mw, scene, 9, 5);
            cmg->start();
            connect(cmg, &ChickenMatrixGame::closeChickenMatrixGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 2)
      {
            WaveChickenGame *wcg = new WaveChickenGame(mw, scene, 12, 3);
            wcg->start();
            connect(wcg, &WaveChickenGame::closeWaveChickenGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 3)
      {
            MeteorShowerGame *msg = new MeteorShowerGame(mw, scene, 8, 9);
            msg->start();
            connect(msg, &MeteorShowerGame::closeMeteorShowerGame, this, &MainGameWindow::setUserMessage);
      }
}

void MainGameWindow::slot_level6()
{
      if (waveCounter == 1)
      {
            EggChickenGame *ecg = new EggChickenGame(mw, scene, 40);
            ecg->start();
            connect(ecg, &EggChickenGame::closeEggChickenGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 2)
      {
            BalloonGame *bg = new BalloonGame(mw, scene, 10, 4);
            bg->start();
            connect(bg, &BalloonGame::closeBalloonGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 3)
      {
            if (!mw->isHard())
                  bigEggGame(100);
            else
                  bigEggGame(200);
      }
}

void MainGameWindow::slot_level7()
{
      if (waveCounter == 1)
      {
            PlanetChickenGame *pcg = new PlanetChickenGame(mw, scene, 12, 1);
            pcg->start();
            connect(pcg, &PlanetChickenGame::closePlanetChickenGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 2)
      {
            sideMeteorShowerGame *smsg = new sideMeteorShowerGame(mw, scene, 8, 9);
            smsg->start();
            connect(smsg, &sideMeteorShowerGame::closeSideMeteorShowerGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 3)
      {
            SideChickenGame *scg = new SideChickenGame(mw, scene, 20);
            scg->start();
            connect(scg, &SideChickenGame::closeSideChickenGame, this, &MainGameWindow::setUserMessage);
      }
}

void MainGameWindow::slot_level8()
{
      if (waveCounter == 1)
      {
            ChickenMatrixGame *cmg = new ChickenMatrixGame(mw, scene, 10, 6);
            cmg->start();
            connect(cmg, &ChickenMatrixGame::closeChickenMatrixGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 2)
      {
            MeteorShowerGame *msg = new MeteorShowerGame(mw, scene, 8, 11);
            msg->start();
            connect(msg, &MeteorShowerGame::closeMeteorShowerGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 3)
      {
            WaveChickenGame *wcg = new WaveChickenGame(mw, scene, 12, 3);
            wcg->start();
            connect(wcg, &WaveChickenGame::closeWaveChickenGame, this, &MainGameWindow::setUserMessage);
      }
}

void MainGameWindow::slot_level9()
{
      if (waveCounter == 1)
      {
            EggChickenGame *ecg = new EggChickenGame(mw, scene, 50);
            ecg->start();
            connect(ecg, &EggChickenGame::closeEggChickenGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 2)
      {
            BalloonGame *bg = new BalloonGame(mw, scene, 10, 5);
            bg->start();
            connect(bg, &BalloonGame::closeBalloonGame, this, &MainGameWindow::setUserMessage);
      }
      else if (waveCounter == 3)
      {
            BossGame *bg = new BossGame(mw, scene, 100);
            bg->start();
            connect(bg, &BossGame::closeBossGame, this, &MainGameWindow::setUserMessage);
      }
}

void MainGameWindow::stopPrepareMusic() { mw->gamePrepareSound->stop(); }

void MainGameWindow::playPrepareMusic() { mw->gamePrepareSound->play(); }

void MainGameWindow::endOfGame()
{
      mw->backGroundMusic->play();

      if (mw->active_player->getLives() == 0) updatePlayer(this->current_high_score);

      deleteLater();
}

void MainGameWindow::continueGame()
{
      mw->setFreezeScene(false);
      animation->start();
}

void MainGameWindow::victory()
{
      if (mw->getDesiredLevel() != 9)
      {
            if (mw->getReachedLevel() == mw->getDesiredLevel()) mw->setReachedLevel(mw->getReachedLevel() + 1);
            updatePlayer(this->current_high_score);
            mw->victorySound->stop();
            mw->backGroundMusic->play();
            mw->openChooseLevelWindow();
            deleteLater();
      }
      else
      {
            updatePlayer(this->current_high_score);
            winWindow *ww = new winWindow(mw);
            ww->setWindowState(Qt::WindowFullScreen);
            ww->exec();
            deleteLater();
      }
}

MainGameWindow::~MainGameWindow() { delete ui; }

int MainGameWindow::getFly_speed() const { return fly_speed; }

void MainGameWindow::setFly_speed(int value) { fly_speed = value; }

void MainGameWindow::level1()
{
      QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);

      connect(this, &MainGameWindow::gameStart, this, &MainGameWindow::slot_level1);

      connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
      timer->start(200);
}

void MainGameWindow::level2()
{
      QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);

      connect(this, &MainGameWindow::gameStart, this, &MainGameWindow::slot_level2);

      connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
      timer->start(200);
}

void MainGameWindow::level3()
{
      QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);

      connect(this, &MainGameWindow::gameStart, this, &MainGameWindow::slot_level3);

      connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
      timer->start(200);
}

void MainGameWindow::level4()
{
      QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);

      connect(this, &MainGameWindow::gameStart, this, &MainGameWindow::slot_level4);

      connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
      timer->start(200);
}

void MainGameWindow::level5()
{
      QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);

      connect(this, &MainGameWindow::gameStart, this, &MainGameWindow::slot_level5);

      connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
      timer->start(200);
}

void MainGameWindow::level6()
{
      QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);

      connect(this, &MainGameWindow::gameStart, this, &MainGameWindow::slot_level6);

      connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
      timer->start(200);
}

void MainGameWindow::level7()
{
      QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);

      connect(this, &MainGameWindow::gameStart, this, &MainGameWindow::slot_level7);

      connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
      timer->start(200);
}

void MainGameWindow::level8()
{
      QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);

      connect(this, &MainGameWindow::gameStart, this, &MainGameWindow::slot_level8);

      connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
      timer->start(200);
}

void MainGameWindow::level9()
{
      QTimer::singleShot(0, this, &MainGameWindow::setUserMessage);

      connect(this, &MainGameWindow::gameStart, this, &MainGameWindow::slot_level9);

      connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
      timer->start(200);
}

void MainGameWindow::start()
{
      spaceship->setStartingPosition(width / 2 - 65, height - 120);

      spaceship->setPos(spaceship->getStartingXPos(), spaceship->getStartingYPos());
      scene->addItem(spaceship);

      this->current_high_score = mw->active_player->getScore();

      if (mw->getDesiredLevel() == 1)
      {
            level1();
      }
      else if (mw->getDesiredLevel() == 2)
      {
            level2();
      }
      else if (mw->getDesiredLevel() == 3)
      {
            level3();
      }
      else if (mw->getDesiredLevel() == 4)
      {
            level4();
      }
      else if (mw->getDesiredLevel() == 5)
      {
            level5();
      }
      else if (mw->getDesiredLevel() == 6)
      {
            level6();
      }
      else if (mw->getDesiredLevel() == 7)
      {
            level7();
      }
      else if (mw->getDesiredLevel() == 8)
      {
            level8();
      }
      else if (mw->getDesiredLevel() == 9)
      {
            level9();
      }
}

void MainGameWindow::setUserMessage()
{
      if (waveCounter == 0 && mw->getDesiredLevel() == 1)
      {
            QPixmap pm(":/images/backgrounds/wave1.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 1 && mw->getDesiredLevel() == 1)
      {
            QPixmap pm(":/images/backgrounds/wave2.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 2 && mw->getDesiredLevel() == 1)
      {
            QPixmap pm(":/images/backgrounds/wave3.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 0 && mw->getDesiredLevel() == 2)
      {
            QPixmap pm(":/images/backgrounds/wave4.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 1 && mw->getDesiredLevel() == 2)
      {
            QPixmap pm(":/images/backgrounds/wave5.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 2 && mw->getDesiredLevel() == 2)
      {
            QPixmap pm(":/images/backgrounds/wave6.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 0 && mw->getDesiredLevel() == 3)
      {
            QPixmap pm(":/images/backgrounds/wave7.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 1 && mw->getDesiredLevel() == 3)
      {
            QPixmap pm(":/images/backgrounds/wave8.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 2 && mw->getDesiredLevel() == 3)
      {
            QPixmap pm(":/images/backgrounds/wave9.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 0 && mw->getDesiredLevel() == 4)
      {
            QPixmap pm(":/images/backgrounds/wave10.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 1 && mw->getDesiredLevel() == 4)
      {
            QPixmap pm(":/images/backgrounds/wave11.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 2 && mw->getDesiredLevel() == 4)
      {
            QPixmap pm(":/images/backgrounds/wave12.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 0 && mw->getDesiredLevel() == 5)
      {
            QPixmap pm(":/images/backgrounds/wave13.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 1 && mw->getDesiredLevel() == 5)
      {
            QPixmap pm(":/images/backgrounds/wave14.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 2 && mw->getDesiredLevel() == 5)
      {
            QPixmap pm(":/images/backgrounds/wave15.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 0 && mw->getDesiredLevel() == 6)
      {
            QPixmap pm(":/images/backgrounds/wave16.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 1 && mw->getDesiredLevel() == 6)
      {
            QPixmap pm(":/images/backgrounds/wave17.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 2 && mw->getDesiredLevel() == 6)
      {
            QPixmap pm(":/images/backgrounds/wave18.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 0 && mw->getDesiredLevel() == 7)
      {
            QPixmap pm(":/images/backgrounds/wave19.png");
            message->setPixmap(pm.scaled(width, height));
      }

      else if (waveCounter == 1 && mw->getDesiredLevel() == 7)
      {
            QPixmap pm(":/images/backgrounds/wave20.png");
            message->setPixmap(pm.scaled(width, height));
      }

      else if (waveCounter == 2 && mw->getDesiredLevel() == 7)
      {
            QPixmap pm(":/images/backgrounds/wave21.png");
            message->setPixmap(pm.scaled(width, height));
      }

      else if (waveCounter == 0 && mw->getDesiredLevel() == 8)
      {
            QPixmap pm(":/images/backgrounds/wave22.png");
            message->setPixmap(pm.scaled(width, height));
      }

      else if (waveCounter == 1 && mw->getDesiredLevel() == 8)
      {
            QPixmap pm(":/images/backgrounds/wave23.png");
            message->setPixmap(pm.scaled(width, height));
      }

      else if (waveCounter == 2 && mw->getDesiredLevel() == 8)
      {
            QPixmap pm(":/images/backgrounds/wave24.png");
            message->setPixmap(pm.scaled(width, height));
      }

      else if (waveCounter == 0 && mw->getDesiredLevel() == 9)
      {
            QPixmap pm(":/images/backgrounds/wave25.png");
            message->setPixmap(pm.scaled(width, height));
      }

      else if (waveCounter == 1 && mw->getDesiredLevel() == 9)
      {
            QPixmap pm(":/images/backgrounds/wave26.png");
            message->setPixmap(pm.scaled(width, height));
      }

      else if (waveCounter == 2 && mw->getDesiredLevel() == 9)
      {
            QPixmap pm(":/images/backgrounds/wave27.png");
            message->setPixmap(pm.scaled(width, height));
      }
      else if (waveCounter == 3)
      {
            scene->removeItem(score);
            updateable = false;
            QPixmap pm(":/images/backgrounds/congratulations.png");
            message->setPixmap(pm.scaled(width, height));

            message->setPos(0, 0);
            scene->addItem(message);
            mw->victorySound->play();
            mw->setProjectilesLevel(spaceship->getProjectilesLevel());

            QTimer::singleShot(5000, this, &MainGameWindow::victory);
            return;
      }

      QTimer::singleShot(0, this, &MainGameWindow::playPrepareMusic);
      QTimer::singleShot(3500, this, &MainGameWindow::stopPrepareMusic);

      message->setPos(0, 0);
      scene->addItem(message);
      ++waveCounter;

      QTimer::singleShot(3500, this, &MainGameWindow::removeMessage);
}

void MainGameWindow::openQuitGameWindow()
{
      QuitGameWindow *qgw = new QuitGameWindow(this);
      qgw->setWindowFlags(Qt::CustomizeWindowHint);
      openedQuitWindow = true;

      qgw->setFocus();
      qgw->exec();
}

void MainGameWindow::bigEggGame(int health)
{
      bigEgg *egg = new bigEgg(mw);
      egg->setHealth(health);
      egg->setPos(width / 2 - 210, pos().y() + 10);
      scene->addItem(egg);

      egg->throw_bullets();
      connect(egg, &bigEgg::endOfBigEggGame, this, &MainGameWindow::setUserMessage);
}

void MainGameWindow::keyPressEvent(QKeyEvent *event)
{
      if (event->key() == Qt::Key_Escape)
      {
            mw->setFreezeScene(true);
            animation->pause();
            mw->pauseAllSounds();
            openQuitGameWindow();
      }
      if (event->key() == Qt::Key_Space)
      {
            if (!mw->getFreezeScene())
            {
                  if (spaceship->getThrowingAllowed())
                  {
                        spaceship->setThrowingAllowed(false);
                        spaceship->throw_projectile();
                  }
            }
      }
      if (event->key() == Qt::Key_A)
      {  // change it to be LeftArrow
            if (!mw->getFreezeScene())
            {
                  spaceship->setDirection(-1);
                  spaceship->start_moving_timer();
            }
      }
      if (event->key() == Qt::Key_D)
      {  // change it to be LeftArrow
            if (!mw->getFreezeScene())
            {
                  spaceship->setDirection(1);
                  spaceship->start_moving_timer();
            }
      }

      QWidget::keyPressEvent(event);
}

void MainGameWindow::keyReleaseEvent(QKeyEvent *event)
{
      switch (event->key())
      {
            case Qt::Key_A:  // change it to be LeftArrow
                  spaceship->setDirection(0);

                  spaceship->stop_moving_timer();
                  break;
            case Qt::Key_D:  // change it to be RightArrow
                  spaceship->setDirection(0);
                  spaceship->stop_moving_timer();
                  break;
            default:
                  QWidget::keyPressEvent(event);
      }
}

void MainGameWindow::increaseScore(int step)
{
      int diff = mw->active_player->getDifficulty();
      if (diff)
      {
            step = step * 2;
      }
      mw->getScore()->increaseScore(step);
      mw->getScore()->setPlainText(QString("Score: ") + QString::number(mw->getScore()->getScore()));
}

void MainGameWindow::updatePlayer(int current_high_score)
{
      QSqlDatabase mydb = QSqlDatabase::database();
      QSqlQuery *qry = new QSqlQuery(mydb);
      QString active_player = mw->active_player->getName();
      std::string content = "anon";
      QString str = QString::fromUtf8(content.c_str());
      if (active_player == str)
      {
            delete (qry);
            return;
      }
      int score = mw->getScore()->getScore();
      if (score > current_high_score)
      {
            qry->prepare("update players set score = :score, level = :level where name = :active_player");
            qry->bindValue(":active_player", active_player);
            qry->bindValue(":score", score);
            qry->bindValue(":level", mw->getReachedLevel());
            qry->exec();
            mydb.commit();
      }
      delete (qry);
      spaceship->setNumOfLives(mw->active_player->getLives());
}

void MainGameWindow::updateLives()
{
      if (mw->active_player->getLives() == 2)
      {
            scene->removeItem(lives);
            QPixmap lv(":/images/spaceships/lives2.png");
            lives->setPixmap(lv);
            lives->setPos(width - 150, 0);
            scene->addItem(lives);
      }
      else if (mw->active_player->getLives() == 1)
      {
            scene->removeItem(lives);
            QPixmap lv(":/images/spaceships/lives1.png");
            lives->setPixmap(lv);
            lives->setPos(width - 150, 0);
            scene->addItem(lives);
      }
}

void MainGameWindow::showChangedScore()
{
      if (updateable)
      {
            scene->removeItem(score);
            score = mw->getScore();
            scene->addItem(score);
      }
}
