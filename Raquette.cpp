#include "Raquette.hpp"
#include <SFML/Graphics.hpp>

Raquette::Raquette(int x, int y)
	:mPos(x, y),
	mRect(sf::Vector2f(15, 100))
{
	mRect.setPosition(mPos);
	mRect.setFillColor(sf::Color::White);
}

sf::RectangleShape Raquette::getRectangle()
{
	return mRect;
}

void Raquette::setPos(int y)
{
	mPos.y += y;
}