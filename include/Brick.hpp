#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

struct Brick {
    sf::RectangleShape shape;
    bool destroyed = false;

    Brick(float x, float y, const sf::Vector2f& size = {60.f, 20.f})
    {
        shape.setSize(size);
        shape.setFillColor(sf::Color::White);

        // Correction SFML 3 : setPosition prend un Vector2f
        shape.setPosition({x, y});
    }
};

// Prototype de création
void createbrick(std::vector<Brick>& briques);
