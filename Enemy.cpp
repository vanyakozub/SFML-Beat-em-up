//
// Created by Ivan on 01.07.2020.
//

#include "Enemy.h"

Enemy::Enemy() {
    enemyTexture.loadFromFile("resources\\enemies\\enemy12.png");
    enemySprite.setTexture(enemyTexture);
    posx = 150;
    posy = 300;
    enemySprite.setPosition(550, 300);
    size = 2*144;
    alive = true;

}

Enemy::~Enemy() {

}
void Enemy::setAlive(bool) {
    alive = false;
}
bool Enemy::getAlive() {
    return alive;
}

void Enemy::setHP(int newhp) {
    this->hp = newhp;

}

int Enemy::getHP() {
    return hp;
}
