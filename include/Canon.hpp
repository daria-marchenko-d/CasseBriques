#pragma once
#include <SFML/Graphics.hpp>

class Canon {
private:
    sf::RectangleShape shape;
    float playerSpeed;
    float playerVelocity;

public:
    Canon();

    void handleInput(float dt);
    void update(float dt, const sf::RenderWindow& window);

    sf::RectangleShape& getShape();
    sf::FloatRect getBounds() const;
};


