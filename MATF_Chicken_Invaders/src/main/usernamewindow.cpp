#include "headers/main_h/usernamewindow.h"
#include "ui_usernamewindow.h"
#include "headers/main_h/player.h"
#include "headers/main_h/hofwindow.h"

void UsernameWindow::onOk()
{
    mw->getScore()->resetScore();
    QString name = ui->lineEdit->text();

    if(name.compare("") != 0){
        mw->getScore()->resetScore();


        QSqlDatabase mydb = QSqlDatabase::database();
        QSqlQuery *qry = new QSqlQuery(mydb);
        qry->prepare("select * from players where name = (:name)");
        qry->bindValue(":name", name);
        qry->exec();
        qry->next();
        if (!qry->isValid()){
            int score = 0;
            int level = 1;
            int difficulty = 0;

            if(mw->isHard()){
                difficulty = 1;
            }

            qry->prepare("insert into Players (name, score, level, difficulty) values (:name, :score, :level, :difficulty)");
            qry->bindValue(":name", name);
            qry->bindValue(":score", score);
            qry->bindValue(":level", level);
            qry->bindValue(":difficulty", difficulty);
            qry->exec();
            mydb.commit();


            mw->setReachedLevel(level);
            mw->active_player = new Player(name, score, level, difficulty);
            mw->setHard(difficulty == 1 ? true:false);
            }
            else {
                int level = qry->value(2).toInt();
                int score = qry->value(1).toInt();
                int diff = qry->value(3).toInt();

                mw->setReachedLevel(level);
                mw->active_player = new Player(name, score, level, diff);

                if(diff){
                    mw->setHard(true);
                }
                else mw->setHard(false);
            }


        if(mw->getReachedLevel() == 1)
            m_ready = true;
        else
            m_levelChooseReady = true;
        delete this;
    }
}

void UsernameWindow::onSkip()
{
    mw->getScore()->resetScore();
    mw->active_player = new Player("anon", 0, 1, mw->isHard()? 1 : 0);
    mw->setReachedLevel(1);
    mw->setDesiredLevel(1);
    m_ready = true;
    delete this;
}

void UsernameWindow::onCancel()
{
    delete this;
}

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
