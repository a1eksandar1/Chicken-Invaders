#ifndef HOFWINDOW_H
#define HOFWINDOW_H

#include "headers/mainwindow.h"

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "headers/player.h"

namespace Ui {
class HofWindow;
}

class HofWindow : public QDialog
{
    Q_OBJECT

protected:
    void resizeEvent(QResizeEvent *) override;

public:
    explicit HofWindow(MainWindow *parent = nullptr);
    ~HofWindow();

    void onBack();
    void LoadData();
    void insertPlayer(Player player);

private slots:
    void on_SqlButton_clicked();

private:
    Ui::HofWindow *ui;
    MainWindow* mw;
//    QSqlDatabase mydb;
};

#endif // HOFWINDOW_H
