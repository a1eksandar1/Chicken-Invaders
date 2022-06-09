#include "headers/main_h/score.h"

#include <QFont>
#include <QLabel>

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent)

{
      setPlainText(QString("Score: ") + QString::number(this->score));
      setDefaultTextColor(Qt::white);
      setFont(QFont("times", 30, QFont::ExtraBold));
}

void Score::increaseScore(int step) { score = score + step; }

int Score::getScore() { return score; }

void Score::resetScore()
{
      this->score = 0;

      setPlainText(QString("Score: ") + QString::number(this->score));
}
