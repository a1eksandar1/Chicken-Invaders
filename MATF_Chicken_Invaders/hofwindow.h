#ifndef HOFWINDOW_H
#define HOFWINDOW_H

#include <QDialog>

namespace Ui {
class HofWindow;
}

class HofWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HofWindow(QWidget *parent = nullptr);
    ~HofWindow();

private:
    Ui::HofWindow *ui;
};

#endif // HOFWINDOW_H
