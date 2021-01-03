#include "headers/player.h"

Player::Player(QString name, int score, int level, bool difficulty)
{
    this->name = name;
    this->score = score;
    this->difficulty = difficulty;
    this->level = level;
}

QString Player::getName(){
    return this->name;
}
int Player::getScore(){
    return this->score;
}
int Player::getLevel(){
    return this->level;
}
int Player::getDifficulty(){
    return this->difficulty;
}

void Player::setScore(int newScore){
    this->score = newScore;
}
