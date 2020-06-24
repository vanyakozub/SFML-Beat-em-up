#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    std::cout << "Hello, World!" << std::endl;
    int width = 800;
    int height = 600;
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    //sf::RectangleShape(25,36);
    /*sf::Vector2 s = sf::Vector2<float>(100 +25, 35);    sf::RectangleShape rect(s);
    rect.setFillColor(sf::Color::Red);*/
    sf::Texture texture1;
    float currentFrame = 0;
    /*if (!texture1.loadFromFile("resources\\main_hero\\run.png", sf::IntRect(10, 10, 32, 32)))
    {
        // ошибка...
    }*/
    texture1.loadFromFile("resources\\main_hero\\run.png");
    //texture1.loadFromFile("resources\\2.1.jpg");
    //sf::RenderTexture(path_of_texture);
    //sf::Texture texture = sf::Texture(path_of_texture.c_str());
    sf::Sprite sprite;
    sprite.setTexture(texture1);
    sprite.setPosition(50, 100);
    sprite.setTextureRect(sf::IntRect(0,0, 144, 144));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            sprite.move(-0.1, 0);
            currentFrame+=0.01;
            if(currentFrame>6)
            {
                currentFrame-=6;
            }
            std::cout << currentFrame<< std::endl;
            sprite.setTextureRect(sf::IntRect(144*int(currentFrame),0,144,144));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            sprite.move(0.1, 0);
            currentFrame+=0.01;
            if(currentFrame>6)
            {
                currentFrame-=6;
            }
            std::cout << currentFrame<< std::endl;
            sprite.setTextureRect(sf::IntRect(144*int(currentFrame)+144,0,-144,144));

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            sprite.move(0, -0.1);
        }



        window.clear();
        //window.draw(shape);
        //window.draw(rect);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
