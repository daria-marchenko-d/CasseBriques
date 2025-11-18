#include "Ball.hpp"
#include <iostream>

Ball::Ball() {
    shape.setRadius(10);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(910/2 - 62.5f, 512 - 125.f));

    ballSpeed = 300.f;
    ballVelocity = sf::Vector2f(-0.08f, -0.08f);
}

void Ball::update(float dt, const sf::RenderWindow& window) {
    shape.move(ballVelocity);

    if (shape.getPosition().x <= 0.f) {
        ballVelocity.x = ballSpeed * dt;
    }
    else if (shape.getPosition().x > window.getSize().x - shape.getRadius()) {
        ballVelocity.x = -ballSpeed * dt;
    }

    if (shape.getPosition().y < 0.f) {
        ballVelocity.y = ballSpeed * dt;
    }
    else if (shape.getPosition().y + shape.getRadius() * 2.f > window.getSize().y) {
        std::cout << "Game Over!" << std::endl;
        ballVelocity = sf::Vector2f(0.f, 0.f);
    }
}

sf::CircleShape& Ball::getShape() {
    return shape;
}

sf::FloatRect Ball::getBounds() const {
    return shape.getGlobalBounds();
}

sf::Vector2f& Ball::getVelocity() {
    return ballVelocity;
}

void Ball::setVelocity(sf::Vector2f vel) {
    ballVelocity = vel;
}

float Ball::getSpeed() const {   
    return ballSpeed;
}

