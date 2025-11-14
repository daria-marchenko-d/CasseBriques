#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

// Function to check FloatRects intersection
bool intersects(const sf::FloatRect& a, const sf::FloatRect& b) {
    return (a.position.x < b.position.x + b.size.x &&
            a.position.x + a.size.x > b.position.x &&
            a.position.y < b.position.y + b.size.y &&
            a.position.y + a.size.y > b.position.y);
}

int main() {
    sf:: Clock clock;
    float deltaTime = 0.0f;
    float playerVelocity;
    sf::Vector2 ballVelocity(-0.08f, -0.08f);

    // Speed
    float playerSpeed = 400; 
    float ballSpeed = 300;
    sf::RenderWindow window(sf::VideoMode({910, 512}), "Casse Brique", sf::Style::Close);

    // Player
    sf::RectangleShape player(sf::Vector2f(125, 25));
    player.setFillColor(sf::Color::Blue);
    player.setPosition(sf::Vector2f(910/2-(player.getSize().x / 2), 512 - player.getSize().y - 10));
    
    
    // Ball
    sf::CircleShape ball(10);
    ball.setFillColor(sf::Color::Green);
    ball.setPosition(sf::Vector2f(910/2 - (player.getSize().x / 2) + 50, 512 - player.getSize().y - 100));
    
    // Collision
    sf::FloatRect nextPos;

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

    sf::FloatRect ballBounds = ball.getGlobalBounds();
    sf::FloatRect playerBounds = player.getGlobalBounds();

    // Collision with player
    nextPos = ballBounds;
    nextPos.position.x += ballVelocity.x;

    if (intersects(playerBounds, nextPos)) {
        ballVelocity.y = -ballSpeed * deltaTime;
    }

    // Ball sides collision
    // left side
    if (ball.getPosition().x <= 0.f) {
        ballVelocity.x = ballSpeed * deltaTime;
    }
    // right side
    else if (ball.getPosition().x > window.getSize().x - ball.getRadius()) {
        ballVelocity.x = -ballSpeed * deltaTime;
    }
    // top side
    else if (ball.getPosition().y <0.f) {
        ballVelocity.y = ballSpeed * deltaTime;
    }
    // bottom side
    else if (ball.getPosition().y +ball.getRadius()*2.f > window.getSize().y) {
        std::cout << "Game Over!" << std::endl;
        ballVelocity = sf::Vector2f(0.f, 0.f);
    }
    // else {
    //     std::cout << "Error" << std::endl;
    // }

    // Move objects
    player.move(sf::Vector2f (playerVelocity, 0.0f));
    ball.move(ballVelocity);

    if (player.getPosition().x < 0.f) {
        player.setPosition(sf::Vector2f(0.f, player.getPosition().y));
    }
    else if (player.getPosition().x + player.getGlobalBounds().size.x > window.getSize().x) {
        player.setPosition(sf::Vector2f(window.getSize().x - player.getGlobalBounds().size.x, player.getPosition().y));
    }

        window.clear();
        window.draw(player);
        window.draw(ball); 
        window.display();
    }
}

