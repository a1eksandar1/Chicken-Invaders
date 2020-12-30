#include "headers/lives.h"

Lives::Lives()
{
    setPixmap(QPixmap(":images/spaceships/lives3.png"));
}

void Lives::set1LivesPic()
{
    setPixmap(QPixmap(":images/spaceships/lives1.png"));
}

void Lives::set2LivesPic()
{
    setPixmap(QPixmap(":images/spaceships/lives2.png"));
}
