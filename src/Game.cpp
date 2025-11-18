#include "Game.hpp"
#include "Collision.hpp"
#include <iostream>

Game::Game()
    : window(sf::VideoMode({910, 512}), "Casse Brique", sf::Style::Close)
{}

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

void Game::update(float dt) {
    player.update(dt, window);
    ball.update(dt, window);

    handleCollisions(dt);
}

void Game::handleCollisions(float dt) {
    sf::FloatRect ballBounds = ball.getBounds();
    sf::FloatRect playerBounds = player.getBounds();

    sf::FloatRect nextPos = ballBounds;
    nextPos.position.x += ball.getVelocity().x;

    if (Collision::intersects(playerBounds, nextPos)) {
        sf::Vector2f vel = ball.getVelocity();
        vel.y = -ball.getSpeed() * dt; 
        ball.setVelocity(vel);
    }
}

void Game::render() {
    window.clear();
    window.draw(player.getShape());
    window.draw(ball.getShape());
    window.display();
}
