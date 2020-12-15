#include "headers/maingamewindow.h"
#include "ui_maingamewindow.h"
#include <QScreen>

void MainGameWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        for(size_t i=0, n = scene->items().size(); i<n; i++)
        {
            scene->items()[i]->setEnabled(false);
        }
        scene->clear();
        mw->backGroundMusic->stop();
        mw->backGroundMusic->setMedia(QUrl("qrc:/sounds/sounds/MainTheme2.mp3"));
        mw->backGroundMusic->play();
        delete this;
        break;
    case Qt::Key_Space:
        if(spaceship->getThrowingAllowed()){
            spaceship->setThrowingAllowed(false);
            spaceship->throw_projectile();
        }
        break;
    case Qt::Key_A: // change it to be LeftArrow
        spaceship->move_left();
        break;
    case Qt::Key_D: // change it to be RightArrow
        spaceship->move_right();
        break;
    case Qt::Key_W: // change it to be UpArrow
        spaceship->move_up();
        break;
    case Qt::Key_S: // change it to be DownArrow
        spaceship->move_down();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

MainGameWindow::MainGameWindow(MainWindow *parent) :
    ui(new Ui::MainGameWindow),
    mw(parent),
    scene(new QGraphicsScene(this)),
    fly_speed(20000),
    spaceship(new Spaceship(mw))
{
    ui->setupUi(this);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    ui->graphicsView->setScene(scene);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    scroll = new QScrollBar;
    scroll = ui->graphicsView->verticalScrollBar();

    QPixmap bkgnd(":/images/backgrounds/gameBackground.png");

    background = new AnimatedGraphicsItem;
    background->setPixmap(bkgnd);

    animation = new QPropertyAnimation(background, "pos");
    animation->setLoopCount(-1);
    animation->setDuration(fly_speed);
    animation->setStartValue(QPoint(0,-2*height));
    animation->setEndValue(QPoint(0,0));
    animation->start();

    scene->addItem(background);
    scene->setFocus();
    scene->setSceneRect(0,0,width-30,height-30);

    spaceship->setStartingPosition(width/2-65, height-120);

    spaceship->setPos(spaceship->getStartingXPos(), spaceship->getStartingYPos());
    scene->addItem(spaceship);
}

MainGameWindow::~MainGameWindow()
{
    delete ui;
}
