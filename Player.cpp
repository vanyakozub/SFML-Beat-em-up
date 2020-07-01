//
// Created by Ivan on 27.06.2020.
//

#include "Player.h"

Player::Player()
{
    playerTexture.loadFromFile("resources\\main_hero\\playermore.png");
    playerSprite.setTexture(playerTexture);
    posx= 150;
    posy = 300;
    playerSprite.setPosition(150, 300);
    size = 2*144;
    damage = 5;



}

int Player::getHP() {
    return this->hp;
}

Player::~Player() {

}

int Player::getDamage() {
    return damage;

}
