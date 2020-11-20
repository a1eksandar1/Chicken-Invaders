#ifndef USERNAMEWINDOW_H
#define USERNAMEWINDOW_H

#include <QDialog>

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
    UsernameWindow(QWidget *parent = nullptr);
    ~UsernameWindow();

private:
    Ui::UsernameWindow *ui;
};

#endif // USERNAMEWINDOW_H

