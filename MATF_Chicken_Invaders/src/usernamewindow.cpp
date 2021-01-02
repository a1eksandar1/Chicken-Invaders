#include "headers/usernamewindow.h"
#include "ui_usernamewindow.h"
#include "headers/player.h"
#include "headers/hofwindow.h"

void UsernameWindow::onOk()
{

    QString name = ui->lineEdit->text();



    QSqlDatabase mydb = QSqlDatabase::database();
    QSqlQuery *qry = new QSqlQuery(mydb);
    qry->prepare("select * from players where name = (:name)");
    qry->bindValue(":name", name);
    qDebug()<< name;
    qry->exec();
    qry->next();
//    qDebug() << qry->
        if (!qry->isValid()){
            qDebug() << "nije usao ovde?";
            int score = 0;
            int level = 1;
            int difficulty = 0;
            qry->prepare("insert into Players (name, score, level, difficulty) values (:name, :score, :level, :difficulty)");
            qry->bindValue(":name", name);
            qry->bindValue(":score", score);
            qry->bindValue(":level", level);
            qry->bindValue(":difficulty", difficulty);
            qry->exec();
            mydb.commit();
            mw->setReachedLevel(level);
        }
        else {
            qDebug() << "usao je u drugi";
            int level = qry->value(2).toInt();
            mw->setReachedLevel(level);
        }


    mw->active_player = name;

    if(mw->getReachedLevel() == 1)
        m_ready = true;
    else
        m_levelChooseReady = true;
    delete this;
}

void UsernameWindow::onSkip()
{
    m_ready = true;
    delete this;
}

void UsernameWindow::onCancel()
{
    delete this;
}

//void UsernameWindow::resizeEvent(QResizeEvent *event)
//{
//    QPixmap bkgnd(":images/backgrounds/usernameWindow.png");
//    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//    QPalette palette;
//    palette.setBrush(QPalette::Window, bkgnd);
//    this->setPalette(palette);


//    QDialog::resizeEvent(event);
//}

UsernameWindow::UsernameWindow(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::UsernameWindow),
    m_ready(false),
    mw(parent)
{
    ui->setupUi(this);

    connect(ui->cancelButton, &QPushButton::clicked, this, &UsernameWindow::onCancel);
    connect(ui->okButton, &QPushButton::clicked, this, &UsernameWindow::onOk);
    connect(ui->skipButton, &QPushButton::clicked, this, &UsernameWindow::onSkip);
}

UsernameWindow::~UsernameWindow()
{
    delete ui;
}

bool UsernameWindow::ready() const
{
    return m_ready;
}

bool UsernameWindow::levelChooseReady()
{
    return m_levelChooseReady;
}

void UsernameWindow::setReady(bool value)
{
    m_ready = value;
}
