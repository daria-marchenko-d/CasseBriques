 #include "Canon.hpp"

Canon::Canon() {
    shape.setSize(sf::Vector2f(125, 25));
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(sf::Vector2f(910/2 - (shape.getSize().x / 2), 512 - shape.getSize().y - 10));

    playerSpeed = 400.f;
    playerVelocity = 0.f;
}

void Canon::handleInput(float dt) {
    playerVelocity = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        playerVelocity = -playerSpeed * dt;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        playerVelocity = playerSpeed * dt;
    }
}

void Canon::update(float dt, const sf::RenderWindow& window) {
    shape.move(sf::Vector2f(playerVelocity, 0.f));

    if (shape.getPosition().x < 0.f) {
        shape.setPosition(sf::Vector2f(0.f, shape.getPosition().y));
    }
    else if (shape.getPosition().x + shape.getGlobalBounds().size.x > window.getSize().x) {
        shape.setPosition(sf::Vector2f(window.getSize().x - shape.getGlobalBounds().size.x, shape.getPosition().y));
    }
}

sf::RectangleShape& Canon::getShape() {
    return shape;
}

sf::FloatRect Canon::getBounds() const {
    return shape.getGlobalBounds();
}
