#include "headers/main_h/score.h"
#include <QFont>
#include <QLabel>

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent)

{
    int value = this->score;

    setPlainText(QString("Score: ") + QString::number(value));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 30, QFont::ExtraBold));

}

void Score::increaseScore(int step)
{
    score = score + step;
}

int Score::getScore()
{
    return score;
}

void Score::resetScore(){
    this->score = 0;
}
