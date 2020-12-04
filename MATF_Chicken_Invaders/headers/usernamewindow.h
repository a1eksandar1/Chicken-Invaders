#ifndef USERNAMEWINDOW_H
#define USERNAMEWINDOW_H

#include <QDialog>
#include "headers/mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UsernameWindow; }
QT_END_NAMESPACE

class UsernameWindow : public QDialog
{
    Q_OBJECT

protected:
    void resizeEvent(QResizeEvent *event) override;

public slots:
    void onOk();
    void onSkip();
    void onCancel();

public:
    UsernameWindow(MainWindow *parent = nullptr);
    ~UsernameWindow();

    bool ready();
    bool levelChooseReady();

private:
    Ui::UsernameWindow *ui;
    bool m_ready;
    bool m_levelChooseReady;
    MainWindow* mw;
};

#endif // USERNAMEWINDOW_H

