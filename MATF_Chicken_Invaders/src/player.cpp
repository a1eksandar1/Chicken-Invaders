#include "headers/player.h"

Player::Player(std::string name, int score, int level, bool difficulty)
{

}

std::string Player::getName(){
    return this->name;
}
int Player::getScore(){
    return this->score;
}
int Player::getLevel(){
    return this->level;
}
bool Player::getDifficulty(){
    return this->difficulty;
}
