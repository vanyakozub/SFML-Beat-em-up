//
// Created by Ivan on 01.07.2020.
//

#include "Enemy.h"

Enemy::Enemy() {
    enemyTexture.loadFromFile("resources\\enemies\\enemy1.png");
    enemySprite.setTexture(enemyTexture);
    posx = 150;
    posy = 300;
    enemySprite.setPosition(550, 300);
    size = 2*144;

}

Enemy::~Enemy() {

}
