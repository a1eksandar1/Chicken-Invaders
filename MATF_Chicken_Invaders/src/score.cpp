#include "headers/score.h"
#include <QFont>
#include <QLabel>

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent)

{
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 20, QFont::ExtraBold));

}

void Score::increaseScore()
{
    ++score;
}

int Score::getScore()
{
    return score;
}
