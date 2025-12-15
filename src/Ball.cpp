#include "Ball.hpp"
#include <iostream>

Ball::Ball() {
    shape.setRadius(10.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({910.f/2.f, 512.f - 50.f});

    speed = 300.f;
    velocity = sf::Vector2f(-150.f, -150.f);
}

void Ball::update(float dt, const sf::RenderWindow& window) {
    shape.move(velocity * dt);

    if (shape.getPosition().x <= 0.f)
        velocity.x = std::abs(velocity.x);

    if (shape.getPosition().x + shape.getRadius()*2.f >= window.getSize().x)
        velocity.x = -std::abs(velocity.x);

    if (shape.getPosition().y <= 0.f)
        velocity.y = std::abs(velocity.y);

    if (shape.getPosition().y + shape.getRadius()*2.f >= window.getSize().y) {
        std::cout << "Game Over!\n";
        velocity = {0.f, 0.f};
    }
}

sf::CircleShape& Ball::getShape() { return shape; }

sf::FloatRect Ball::getBounds() const { return shape.getGlobalBounds(); }

sf::Vector2f& Ball::getVelocity() { return velocity; }

void Ball::setVelocity(const sf::Vector2f& vel) { velocity = vel; }

float Ball::getSpeed() const { return speed; }
