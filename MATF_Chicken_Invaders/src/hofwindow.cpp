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
    connect(ui->SqlButton,&QPushButton::clicked, this, &HofWindow::LoadData);
//    mydb = QSqlDatabase::addDatabase("QSQLITE");
//    mydb.setDatabaseName("/home/cole/Desktop/Projects/15-matf-chicken-invaders/MATF_Chicken_Invaders/database.db");
    QSqlDatabase mydb = QSqlDatabase::database();
//    if(!mydb.open()){
//        ui->NewLabel->setText("cant connect");
//    }
//    else{
//        ui->NewLabel->setText("connected...");
//    }
    ui->NewLabel->setText(mw->active_player);
}

HofWindow::~HofWindow()
{
    delete ui;

}

void HofWindow::LoadData(){
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(mw->mydb);
    // TODO: Lista mora da ima 2 kolone, listview moze samo jednu
    qry->prepare("Select name, score from players");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    std::string ime = "babic";
    Player* player = new Player(ime, 2000, 3);
}

void HofWindow::insertPlayer(Player player){
    QSqlQuery *qry = new QSqlQuery(mw->mydb);
    std::string str = player.getName();
    QString name = QString::fromUtf8(str.c_str());
    int score = player.getScore();
    int level = player.getLevel();
    qry->prepare("insert into players (name, score, level) values ('"+name+"','"+score+"','"+level+"')");
}

void HofWindow::onBack()
{
    close();
}

void HofWindow::on_SqlButton_clicked()
{

}
