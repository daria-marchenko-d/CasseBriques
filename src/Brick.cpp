#include "Brick.hpp"

void createbrick(std::vector<sf::RectangleShape>& briques)
{
    for (int i = 0; i < 10; i++)
    {
        sf::RectangleShape b;
        b.setSize({60.f, 20.f});
        b.setFillColor(sf::Color::White);
        b.setPosition({20.f + i * 60.f, 20.f});

        briques.push_back(b);
    }
}
