#include <SFML/Graphics.hpp>
#include <vector>
#include <Brick.hpp>

using namespace sf;


void createbrick(std::vector<sf::RectangleShape>& briques)
{
    for (int i = 0; i <10; i++){
        sf::RectangleShape b;
        b.setSize(sf::Vector2f(60,20));
        b.setFillColor(sf::Color::White);
        b.setPosition({20.f + i *60.f,20.f});


    }

}
