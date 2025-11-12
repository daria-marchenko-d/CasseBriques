#include <Ball.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

constexpr float ballRadius{10.f}, ballVelocity{8.f};
struct Ball 
{
    CircleShape shape;


    Ball (float mX, float mY)
    {
        // shape.setPosition(mX,mY);
        shape.setRadius(ballRadius);
        shape.setFillColor(Color::Green);
        // shape.setOrigin(ballRadius, ballRadius);
    }
};