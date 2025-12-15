#include "Game.hpp"
#include "Brick.hpp"
#include "Collision.hpp"
#include <iostream>
#include <vector>


Game::Game()
    : window(sf::VideoMode({910, 512}), "Casse Brique", sf::Style::Close)
{
    createbrick(bricks);
}


void Game::run() {
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        if (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        player.handleInput(dt);
        update(dt);
        render();
    }
}

void Game::update(float dt)
{
    player.update(dt, window);
    ball.update(dt, window);

    handleCollisions(dt);
    handleBrickCollisions(dt);
}

void Game::handleBrickCollisions(float dt)
{
    for (auto& brick : bricks)
    {
        if (!brick.destroyed &&
            ball.getShape().getGlobalBounds().findIntersection(brick.shape.getGlobalBounds()))
        {
            auto vel = ball.getVelocity();
            vel.y = -vel.y;
            ball.setVelocity(vel);

            brick.destroyed = true;
            break;
        }
    }


    sf::FloatRect ballBounds = ball.getBounds();
    sf::FloatRect playerBounds = player.getBounds();

    sf::FloatRect nextPos = ballBounds;

    // SFML 3 : position.x remplace left
    nextPos.position.x += ball.getVelocity().x * dt;

    if (playerBounds.findIntersection(nextPos)) {
        sf::Vector2f vel = ball.getVelocity();
        vel.y = -std::abs(vel.y);
        ball.setVelocity(vel);
    }
}

void Game::handleCollisions(float dt)
{
    // Pour l’instant, rien à faire
}


void Game::render()
{
    window.clear();

    window.draw(player.getShape());
    window.draw(ball.getShape());

    for (auto& brick : bricks)
    {
        if (!brick.destroyed)
            window.draw(brick.shape);
    }

    window.display();
}
