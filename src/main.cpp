#include <SFML/Graphics.hpp>
#include <optional>

int main() {
    sf:: Clock clock;
    float deltaTime = 0.0f;
    float playerVelocity;

    // Speed
    float playerSpeed = 400; 

    sf::RenderWindow window(sf::VideoMode({910, 512}), "Casse Brique", sf::Style::Close);
    // Player
    sf::RectangleShape player(sf::Vector2f(125, 25));
    player.setFillColor(sf::Color::Blue);
    player.setPosition(sf::Vector2f(910/2-(player.getSize().x / 2), 512 - player.getSize().y - 10));
    // Ball
    // sf::CircleShape ball(sf::Vector2f(50, 50));
    // ball.setFillColor(sf::Color::Red);
    // ball.setPosition(sf::Vector2f(100, 100));
    // Game loop

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        if (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

    playerVelocity = 0.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        playerVelocity = -playerSpeed * deltaTime;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        playerVelocity = playerSpeed * deltaTime;
    }

    player.move(sf::Vector2f (playerVelocity, 0.0f));

        window.clear();
        window.draw(player); 
        window.display();
    }
}

