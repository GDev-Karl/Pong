#include "Game.hpp"
#include <iostream>
#include <string.h>
using namespace std;

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: mWindow(sf::VideoMode(W, H), "Pong"),
	scoreJ(0),
	scoreM(0),
	ball(W / 2, H / 2),
	batJ(30 , 20),
	batM(W - 45 , 20)
{

}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update();
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// move left...
			batJ.moveLeft();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// move right...
			batJ.moveRight();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// move up...
			batJ.moveUp();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// move down...
			batJ.moveDown();
		}

		
	}
}

void Game::render()
{
	mWindow.clear(sf::Color::Black);
	Draw(ball);
	Draw(batJ);
	Draw(batM);
	displayScore();
	mWindow.display();
}

void Game::Draw(Ball shape)
{
	mWindow.draw(shape.getShape());
}

void Game::Draw(Bat shape)
{
	mWindow.draw(shape.getShape());
}

void Game::displayScore()
{
	string scores = to_string(scoreJ) + " | " + to_string(scoreM);
	sf::Text message;

	sf::Font font;
	font.loadFromFile("PoetsenOne-Regular.ttf");

	message.setFont(font);

	// Make it really big
	message.setCharacterSize(26);

	// Choose a color
	message.setFillColor(sf::Color::White);

	message.setPosition(sf::Vector2f(W / 2 - 20, 20));

	message.setString(scores);

	mWindow.draw(message);
}

void Game::updateMove()
{
	//si la balle touche le bas de la fenetre
	if (ball.getRectPosition().top + 24 > H)
	{
		// changement de direction de la balle
		ball.hitBottom();
	}

	// si la balle touche le haut de la fenetre
	if (ball.getRectPosition().top < 0)
	{
		ball.hitTop();
	}

	// si la balle touche le cote gauche
	if (ball.getRectPosition().left < 0)
	{
		ball.reboundSides();
		scoreM += 1;
	}

	//si la balle touche le cote droit
	if (ball.getRectPosition().left + 12 > W)
	{
		ball.reboundSides();
		scoreJ += 1;
	}

/*
	if (ball.getPosition().x + 24 == batJ.getPosition().x or
		batJ.getPosition().x + 15 == ball.getPosition().x or
		ball.getPosition().x + 24 == batM.getPosition().x or
		batM.getPosition().x + 15 == ball.getPosition().x)
	{
		ball.reboundSides();
	}

	if (ball.getPosition().y + 24 == batJ.getPosition().y or
		batJ.getPosition().y + 100 == ball.getPosition().y or
		ball.getPosition().y + 24 == batM.getPosition().y or
		batM.getPosition().y + 15 == ball.getPosition().y)
	{
		ball.hitTop();
	}
*/

	// Si la balle touche la batte
	if (ball.getRectPosition().intersects(batJ.getRectPosition()) or ball.getRectPosition().intersects(batM.getRectPosition()))
	{
		ball.reboundSides();
		ball.hitTop();
	}

	batM.setPosition(ball.getPosition().y - 50);

}

void Game::update()
{
	updateMove();
	batJ.update();
	batM.update();
	ball.update();

}