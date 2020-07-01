//
// Created by Ivan on 01.07.2020.
//

#ifndef UNTITLED2_ENEMY_H
#define UNTITLED2_ENEMY_H
#include <SFML/Graphics.hpp>

class Enemy {
private:
    sf::Texture enemyTexture;
    int size;
    int hp = 10;
    bool alive;

public:
    Enemy();
    sf::Sprite enemySprite;
    ~Enemy();
    float posx;
    float posy;
    int getHP();
    void setHP(int newhp);
    void setAlive(bool);
    bool getAlive();
};


#endif //UNTITLED2_ENEMY_H
