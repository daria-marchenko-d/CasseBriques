#include <SFML/Graphics.hpp>
#include <optional>

int main()
{
    sf::VideoMode mode({800u, 600u}); // utiliser un sf::Vector2u explicite
    sf::RenderWindow window(mode, "SFML 3 Test");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (auto event = window.pollEvent()) // std::optional<sf::Event>
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
