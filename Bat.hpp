#ifndef BAT_HPP
#define BATT_HPP
#include <SFML/Graphics.hpp>

class Bat
{
	private:
		sf::Vector2f batPosition;
		sf::RectangleShape batShape;
		float batSpeed;

	public:
		Bat(float x, float y);
		sf::FloatRect getRectPosition();
		sf::Vector2f getPosition();
		sf::RectangleShape getShape();
		void setPosition(float y);
		void moveLeft();
		void moveRight();
		void moveDown();
		void moveUp();
		void update();
};

#endif // !BAT_HPP
