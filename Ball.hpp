#ifndef BALL_HPP
#define BALL_HPP
#include <SFML/Graphics.hpp>


class Ball
{
	private:
		sf::Vector2f ballPosition;
		sf::CircleShape ballShape;
		float xVelocity; // vitesse en x
		float yVelocity; // vitesse en y

	public:
		Ball(float x, float y);
		sf::CircleShape getShape();
		sf::FloatRect getRectPosition();
		sf::Vector2f getPosition();
		void reboundSides();
		void hitTop();
		void hitBottom();
		void update();
};

#endif // BALL_HPP
