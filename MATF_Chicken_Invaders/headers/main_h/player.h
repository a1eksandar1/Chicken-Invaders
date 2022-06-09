#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include <string>
class Player
{
     public:
      Player(QString name, int score, int level, bool difficulty);

      QString getName();
      int getScore();
      int getLevel();
      int getDifficulty();
      void setScore(int newScore);
      int getLives();
      void loseLife();

     private:
      QString name;
      int score;
      int level;
      int difficulty;
      int lives;
};

#endif  // PLAYER_H
