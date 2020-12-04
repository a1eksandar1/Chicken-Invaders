#ifndef CHICKEN_H
#define CHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Chicken: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Chicken(int m, int n);
    ~Chicken();

    int getImgChange() const;
    void setImgChange(int value);

    int getOrientation() const;
    void setOrientation(int value);

public slots:
    void eggs();

private:
    int m,n;
    int imgChange;
    int orientation=10;
    int width, height;

protected:
    void advance(int step) override;
};

#endif // CHICKEN_H
