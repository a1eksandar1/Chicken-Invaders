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
    bool getDifficulty();
private:
    std::string name;
    int score;
    int level;
    bool difficulty;
};

#endif // PLAYER_H
