#include "Bat.hpp"
#include <SFML/Graphics.hpp>

Bat::Bat(float x, float y)
	:batPosition(x, y),
	batSpeed(20.f),
	batShape(sf::Vector2f(15, 100))
{
	batShape.setPosition(batPosition);
}

sf::FloatRect Bat::getRectPosition()
{
	return batShape.getGlobalBounds();
}

sf::Vector2f Bat::getPosition()
{
	return batPosition;
}

sf::RectangleShape Bat::getShape()
{
	return batShape;
}

void Bat::setPosition(float y)
{
	batPosition.y  = y;
}

void Bat::moveLeft()
{
	batPosition.x -= batSpeed;
}

void Bat::moveRight()
{
	batPosition.x += batSpeed;
}

void Bat::moveDown()
{
	batPosition.y += batSpeed;
}

void Bat::moveUp()
{
	batPosition.y -= batSpeed;
}

void Bat::update()
{
	batShape.setPosition(batPosition);
}