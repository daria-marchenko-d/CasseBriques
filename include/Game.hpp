#pragma once
#include <SFML/Graphics.hpp>
#include "Canon.hpp"
#include "Ball.hpp"

class Game {
private:
    sf::RenderWindow window;
    sf::Clock clock;

    Canon player;
    Ball ball;

public:
    Game();
    void run();

private:
    void update(float dt);
    void render();
    void handleCollisions(float dt);
};

