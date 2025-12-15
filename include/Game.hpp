#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Canon.hpp"
#include "Ball.hpp"
#include "Brick.hpp"

class Game {
private:
    sf::RenderWindow window;
    sf::Clock clock;

    Canon player;
    Ball ball;
    std::vector<Brick> bricks;

public:
    Game();
    void run();

private:
    void update(float dt);
    void render();
    void handleCollisions(float dt);
    void handleBrickCollisions(float dt);
    
};
