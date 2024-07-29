#include "Snake.h"

Snake::Snake(int windowWidth, int windowHeight)
{
	this->currentPosition = sf::Vector2f((float)windowWidth / 2, (float) windowHeight / 2);
	this->snakeHead = sf::RectangleShape();
	this->snakeHead.setSize(sf::Vector2f(10.0f, 10.0f));
	this->snakeHead.setFillColor(sf::Color::Green);
	this->snakeHead.setPosition(currentPosition);
	this->speed = 2.5f;
	this->currentDirection = RIGHT;
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->currentDirection = RIGHT;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->currentDirection = DOWN;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->currentDirection = LEFT;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->currentDirection = UP;
}

void Snake::Logic()
{
	sf::Vector2f previousPosition = this->currentPosition;

	switch (this->currentDirection)
	{
	case LEFT:
		this->snakeHead.setPosition(previousPosition + sf::Vector2f(-1, 0) * this->speed);
		break;
	case UP:
		this->snakeHead.setPosition(previousPosition + sf::Vector2f(0, -1) * this->speed);
		break;
	case RIGHT:
		this->snakeHead.setPosition(previousPosition + sf::Vector2f(1, 0) * this->speed);
		break;
	case DOWN:
		this->snakeHead.setPosition(previousPosition + sf::Vector2f(0, 1) * this->speed);
		break;
	default:
		break;
	}

	this->currentPosition = this->snakeHead.getPosition();
}


