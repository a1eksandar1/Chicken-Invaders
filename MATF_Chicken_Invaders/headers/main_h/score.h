#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem* parent = 0);
    void increaseScore(int step);
    int getScore();
    void resetScore();

private:
    int score = 0;
};

#endif // SCORE_H
