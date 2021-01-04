#include "headers/player.h"

Player::Player(QString name, int score, int level, bool difficulty)
{
    this->name = name;
    this->score = score;
    this->difficulty = difficulty;
    this->level = level;
    this->lives = 3;
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

void Player::loseLife(){
    this->lives = this->lives - 1;
}

int Player::getLives(){
    return this->lives;
}
