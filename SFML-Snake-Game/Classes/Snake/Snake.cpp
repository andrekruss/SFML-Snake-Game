#include "Snake.h"

Snake::Snake(int windowWidth, int windowHeight)
{
	this->currentPosition = sf::Vector2f((float)windowWidth / 2, (float) windowHeight / 2);
	this->snakeHead = sf::RectangleShape();
	this->snakeHead.setSize(sf::Vector2f(10.0f, 10.0f));
	this->snakeHead.setFillColor(sf::Color::Green);
	this->snakeHead.setPosition(currentPosition);
}

Snake::~Snake()
{
}

void Snake::Setup()
{
}

void Snake::Draw(sf::RenderWindow& window)
{
	window.draw(this->snakeHead);
}

void Snake::Input()
{
}

void Snake::Logic()
{
}


