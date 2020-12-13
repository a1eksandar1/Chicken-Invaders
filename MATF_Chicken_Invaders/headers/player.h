#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
public:
    Player(std::string name, int score, int level);
private:
    std::string name;
    int score;
    int level;
};

#endif // PLAYER_H
