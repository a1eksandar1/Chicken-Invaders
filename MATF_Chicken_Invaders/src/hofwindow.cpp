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
    connect(ui->pushButton, &QPushButton::clicked, this, &HofWindow::onBack);
    connect(ui->SqlButton,&QPushButton::clicked, this, &HofWindow::LoadData);
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/home/cole/Desktop/Projects/15-matf-chicken-invaders/MATF_Chicken_Invaders/database.db");
    if(!mydb.open()){
        ui->NewLabel->setText("cant connect");
    }
    else{
        ui->NewLabel->setText("connected...");
    }
}

HofWindow::~HofWindow()
{
    delete ui;

}

void HofWindow::LoadData(){
    QSqlQuery qry;
    if (qry.exec("Select * from players where score = 222")){
        while(qry.next()){
            ui->NewLabel->setText(qry.value(0).toString());
        }
    }
    std::string ime = "babic";
    Player* player = new Player(ime, 2000, 3);
}

void HofWindow::onBack()
{
    close();
}
