#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
public:
    Player(std::string name, int score, int level, bool difficulty);

    std::string getName();
    int getScore();
    int getLevel();
    int getDifficulty();
private:
    std::string name;
    int score;
    int level;
    int difficulty;
};

#endif // PLAYER_H
