#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.hpp"

void handleBrickCollision(Ball& ball, std::vector<sf::RectangleShape>& bricks);
