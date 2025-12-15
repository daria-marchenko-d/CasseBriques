#include "Collision.hpp"
#include <cmath>

void handleBrickCollision(Ball& ball, std::vector<sf::RectangleShape>& bricks)
{
    sf::FloatRect ballBounds = ball.getBounds();
    sf::Vector2f& velocity = ball.getVelocity();

    for (size_t i = 0; i < bricks.size(); ++i)
    {
        sf::FloatRect brickBounds = bricks[i].getGlobalBounds();

        if (ballBounds.findIntersection(brickBounds))
        {
              // SFML 3 : use position.x / size.x
            float ballCenterX  = ballBounds.position.x + ballBounds.size.x / 2.f;
            float ballCenterY  = ballBounds.position.y + ballBounds.size.y / 2.f;
            float brickCenterX = brickBounds.position.x + brickBounds.size.x / 2.f;
            float brickCenterY = brickBounds.position.y + brickBounds.size.y / 2.f;

            float dx = ballCenterX - brickCenterX;
            float dy = ballCenterY - brickCenterY;

            float overlapX = (brickBounds.size.x / 2.f + ballBounds.size.x / 2.f) - std::abs(dx);
            float overlapY = (brickBounds.size.y / 2.f + ballBounds.size.y / 2.f) - std::abs(dy);

            if (overlapX < overlapY)
                velocity.x = -velocity.x;
            else
                velocity.y = -velocity.y;

            bricks.erase(bricks.begin() + i);
            return;
        }
    }
}
