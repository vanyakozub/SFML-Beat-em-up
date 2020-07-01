#include <iostream>

#include "Player.h"
#include "Enemy.h"

int main() {
    int width = 800;
    int height = 600;
    sf::RenderWindow window(sf::VideoMode(width, height), "Street Fighter");
    sf::Clock clock;
    sf::Texture bg;
    int rightSide = -1;
    float enemystayingFrame = 0;
    float stayingFrame = 0;
    float currentFrame = 0;
    Player player;
    Enemy enemy;
    //player.playerSprite.setPosition(width/2, height/2);
    bg.loadFromFile("resources\\main_hero\\background.png");
    player.playerSprite.setTextureRect(sf::IntRect(0,0, 2*144, 2*144));
    sf::Sprite background;
    background.setTexture(bg);
    bool isHit = false;
    
    while (window.isOpen())
    {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 1800;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        enemystayingFrame += 0.01 * time;
        if (enemystayingFrame > 5) {
            enemystayingFrame -= 5;
        }
        if(enemy.getAlive()) {

            if (rightSide == 1)
                enemy.enemySprite.setTextureRect(
                        sf::IntRect(2 * 144 * int(enemystayingFrame), 0, 2 * rightSide * 144, 2 * 144));
            else
                enemy.enemySprite.setTextureRect(
                        sf::IntRect(2 * 144 * int(enemystayingFrame) + 2 * 144, 0, 2 * rightSide * 144, 2 * 144));
        } else
        {
            enemy.enemySprite.setTextureRect(sf::IntRect (0, 2*144*4, 2 * 144, 2 * 144 ));
        }

        if(isHit) {
            currentFrame += 0.03 * time;
            std::cout << player.playerSprite.getPosition().x << "\t" << enemy.enemySprite.getPosition().x << "\t" << player.posy << "\t" << enemy.posy << std::endl;
            if((currentFrame > 3 && currentFrame < 5)&&abs(player.playerSprite.getPosition().x - enemy.enemySprite.getPosition().x ) < 190 &&abs(player.posy - enemy.posy) <20)
            {


                if(enemy.getAlive())
                enemy.enemySprite.setTextureRect(
                        sf::IntRect(2 * 144 * int(currentFrame), 2*144, 2 * rightSide * 144, 2 * 144));
                else {
                    enemy.enemySprite.setTextureRect(sf::IntRect (0, 2*144*4, 2  * 144, 2 * 144 ));
                }
            }
            if (currentFrame > 5) {
                enemy.setHP(enemy.getHP() - player.getDamage());
                if(enemy.getHP() <=0) {
                    enemy.setAlive(false);
                }
                currentFrame -= 5;
                isHit = false;
            }
            if (isHit) {
                if (rightSide == 1)
                    player.playerSprite.setTextureRect(
                            sf::IntRect(2 * 144 * int(currentFrame), 576 + 144 * 2, 2 * rightSide * 144, 2 * 144));
                else
                    player.playerSprite.setTextureRect(
                            sf::IntRect(2 * 144 * int(currentFrame) + 2 * 144, 576 + 144 * 2, 2 * rightSide * 144,
                                        2 * 144));

            }
        } else {
            stayingFrame += 0.01 * time;
            if (stayingFrame > 5) {
                stayingFrame -= 5;
            }
            if (rightSide == 1)
                player.playerSprite.setTextureRect(
                        sf::IntRect(2 * 144 * int(stayingFrame), 0, 2 * rightSide * 144, 2 * 144));
            else
                player.playerSprite.setTextureRect(
                        sf::IntRect(2 * 144 * int(stayingFrame) + 2 * 144, 0, 2 * rightSide * 144, 2 * 144));

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                if(rightSide== -1){
                    rightSide = 1;
                    currentFrame = 0;
                }

                player.posx -= 0.1;
                enemy.posx += 0.1;
                enemy.enemySprite.move(+0.1,0);
                //player.playerSprite.move(-0.1*time, 0);
                currentFrame += 0.01 * time;
                if (currentFrame > 6) {
                    currentFrame -= 6;
                }
                //std::cout << currentFrame<< std::endl;
                player.playerSprite.setTextureRect(
                        sf::IntRect(2 * 144 * int(currentFrame), 576, 2 * rightSide * 144, 2 * 144));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                if(rightSide==1){
                    rightSide = -1;
                    currentFrame = 0;
                }

                player.posx += 0.1;
                enemy.posx -= 0.1;
                enemy.enemySprite.move(-0.1,0);
                //player.playerSprite.move(0.1*time, 0);
                currentFrame += 0.01 * time;
                if (currentFrame > 6) {
                    currentFrame -= 6;
                }
                //std::cout << currentFrame<< std::endl;
                player.playerSprite.setTextureRect(
                        sf::IntRect(2 * 144 * int(currentFrame) + 2 * 144, 576, 2 * rightSide * 144, 2 * 144));


            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                player.playerSprite.move(0, -0.05);
                player.posy -= 0.05;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                player.playerSprite.move(0, 0.05);
                player.posy += 0.05;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                isHit = true;
                currentFrame = 0;
            }
            background.setTextureRect(sf::IntRect(player.posx - width / 2, 0, width, height));
            int offset = player.playerSprite.getPosition().x - width / 2;
            //player.playerSprite.setPosition(player.playerSprite.getPosition().x - width /2, player.playerSprite.getPosition().y);
            //std::cout << background.getPosition().x << std::endl;
            //background.setPosition(offset,0);

        }
        window.clear();
        window.draw(background);
        window.draw(enemy.enemySprite);
        window.draw(player.playerSprite);

        window.display();
    }

    return 0;
}
