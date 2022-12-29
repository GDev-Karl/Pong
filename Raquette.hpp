#ifndef RAQUETTE_HPP
#define RAQUETTE_HPP
#include <SFML/Graphics.hpp>

class Raquette {

	private:
		sf::Vector2f mPos;
		sf::RectangleShape mRect;
	public:
		Raquette(int x, int y);
		sf::RectangleShape getRectangle();
		void setPos(int y);

};
#endif // !RAQUETTE_HPP
