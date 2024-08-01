#include "Snake.h"
#include <iostream>

Snake::Snake(int windowWidth, int windowHeight)
{
	this->snakeHead = sf::RectangleShape(sf::Vector2f(10.0f, 10.0f));
	this->snakeHead.setFillColor(sf::Color::Green);
	this->snakeHead.setPosition((float)windowWidth / 2, (float)windowHeight / 2);
	this->speed = 10.0f;
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

sf::Vector2f Snake::GetSnakeHeadPosition()
{
	return this->snakeHead.getPosition();
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

void Snake::Update(float frameTime)
{

	switch (this->currentDirection)
	{
	case LEFT:
		this->snakeHead.setPosition(snakeHead.getPosition() + sf::Vector2f(-1, 0) * this->speed);
		break;
	case UP:
		this->snakeHead.setPosition(snakeHead.getPosition() + sf::Vector2f(0, -1) * this->speed);
		break;
	case RIGHT:
		this->snakeHead.setPosition(snakeHead.getPosition() + sf::Vector2f(1, 0) * this->speed);
		break;
	case DOWN:
		this->snakeHead.setPosition(snakeHead.getPosition() + sf::Vector2f(0, 1) * this->speed);
		break;
	default:
		break;
	}

	std::cout << "Current snake position: " << this->snakeHead.getPosition().x << " " << this->snakeHead.getPosition().y << std::endl;
}


