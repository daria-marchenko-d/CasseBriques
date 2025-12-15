#pragma once
#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float speed;

public:
    Ball();

    void update(float dt, const sf::RenderWindow& window);

    sf::CircleShape& getShape();
    sf::FloatRect getBounds() const;

    sf::Vector2f& getVelocity();
    void setVelocity(const sf::Vector2f& vel);

    float getSpeed() const;
};