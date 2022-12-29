#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include "Bat.hpp"
#include "Constantes.hpp"

class Game
{
	private:
		sf::RenderWindow mWindow;
		int scoreJ, scoreM;
		Ball ball;
		Bat batJ, batM;

	private:
		void processEvents();
		void render();
		void displayScore();
		void Draw(Ball ball);
		void Draw(Bat raquet);
		void updateMove();
		void update();

	public:
		Game();
		void run();
		static const sf::Time TimePerFrame;
};

#endif // !GAME_HPP
