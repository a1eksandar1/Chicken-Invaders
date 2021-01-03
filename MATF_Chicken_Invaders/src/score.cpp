#include "headers/score.h"
#include <QFont>
#include <QLabel>

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent)

{
    int value = this->score;

    setPlainText(QString("Score: ") + QString::number(value));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 20, QFont::ExtraBold));

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
