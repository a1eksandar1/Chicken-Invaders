#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
public:
    Player(std::string name, int score, int level);

    std::string getName();
    int getScore();
    int getLevel();
private:
    std::string name;
    int score;
    int level;
};

#endif // PLAYER_H
