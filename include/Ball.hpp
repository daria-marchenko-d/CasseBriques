#pragma once
#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::CircleShape shape;
    sf::Vector2f ballVelocity;
    float ballSpeed;

public:
    Ball();

    void update(float dt, const sf::RenderWindow& window);

    sf::CircleShape& getShape();
    sf::FloatRect getBounds() const;

    sf::Vector2f& getVelocity();
    void setVelocity(sf::Vector2f vel);
    
    float getSpeed() const;
};


