#include "headers/hofwindow.h"
#include "ui_hofwindow.h"
#include "headers/mainwindow.h"

void HofWindow::resizeEvent(QResizeEvent *event)
{
    QPixmap bkgnd(":images/backgrounds/optionsWindowBackground.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    QDialog::resizeEvent(event);
}

HofWindow::HofWindow(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::HofWindow),
    mw(parent)
{
    ui->setupUi(this);
    LoadData();
    connect(ui->pushButton, &QPushButton::clicked, this, &HofWindow::onBack);
//    QSqlDatabase mydb = QSqlDatabase::database();
}

HofWindow::~HofWindow()
{
    delete ui;

}

void HofWindow::LoadData(){
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(mw->mydb);
    qry->prepare("Select name, score from players");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
}

void HofWindow::insertPlayer(Player player){
    QSqlQuery *qry = new QSqlQuery(mw->mydb);
    std::string str = player.getName();
    QString name = QString::fromUtf8(str.c_str());
    int score = player.getScore();
    int level = player.getLevel();
    bool difficulty = player.getDifficulty();
    qry->prepare("insert into players (name, score, level, difficulty) values (:name, :score, :level, :difficulty)");
    qry->bindValue(":name",name);
    qry->bindValue(":score",score);
    qry->bindValue(":level",level);
    qry->bindValue(":difficulty",difficulty);
    qry->exec();
}

void HofWindow::onBack()
{
    close();
}

