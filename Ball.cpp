#include "Ball.hpp"
#include <SFML/Graphics.hpp>

Ball::Ball(float x, float y):
	ballPosition(x, y),
	xVelocity(5.f),
	yVelocity(5.f),
	ballShape(12)
{
	ballShape.setPosition(ballPosition);
}

sf::CircleShape Ball::getShape()
{
	return ballShape;
}

sf::FloatRect Ball::getRectPosition()
{
    return ballShape.getGlobalBounds();
}

sf::Vector2f Ball::getPosition()
{
    return ballPosition;
}

void Ball::reboundSides()
{
    xVelocity = -xVelocity;
}

void Ball::hitTop()
{
    yVelocity = -yVelocity;
}

void Ball::hitBottom()
{
    yVelocity = -yVelocity;
}

void Ball::update()
{
    // Update the ball position variables
    ballPosition.y += yVelocity;
    ballPosition.x += xVelocity;

    // Move the ball and the bat
    ballShape.setPosition(ballPosition);
}