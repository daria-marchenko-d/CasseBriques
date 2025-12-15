#include "Brick.hpp"

void createbrick(std::vector<Brick>& briques)
{
    const int columns = 10;
    const int rows    = 5;

    const float brickWidth  = 60.f;
    const float brickHeight = 20.f;
    const float spacingX    = 5.f;
    const float spacingY    = 10.f;

    const float startX = 20.f;
    const float startY = 20.f;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            sf::RectangleShape b;
            b.setSize({brickWidth, brickHeight});

            float x = startX + col * (brickWidth + spacingX);
            float y = startY + row * (brickHeight + spacingY);
briques.emplace_back(x, y);
            // b.setPosition({ x, y });  // <-- correct

            // briques.emplace_back(b);
        }
    }
}
