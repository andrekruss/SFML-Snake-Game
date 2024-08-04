#include "Snake.h"
#include "../../Enums/eDirection.h"
#include <iostream>

Snake::Snake(int windowWidth, int windowHeight)
{
	this->snake = std::vector<SnakeSegment>();
	sf::Vector2f snakeHeadPosition((float) windowWidth / 2, (float) windowHeight / 2);
	SnakeSegment snakeHead(snakeHeadPosition, eDirection::RIGHT);
	this->snake.push_back(snakeHead);
	this->speed = 5.0f;
}

Snake::~Snake()
{
}

void Snake::Setup()
{
}

void Snake::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < this->snake.size(); i++) {
		window.draw(this->snake[i].GetSnakeSegment());
	}
	//window.draw(this->snakeHead);
}

void Snake::Input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->snake[0].SetCurrentDirection(eDirection::RIGHT);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->snake[0].SetCurrentDirection(eDirection::DOWN);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->snake[0].SetCurrentDirection(eDirection::LEFT);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->snake[0].SetCurrentDirection(eDirection::UP);
}

void Snake::Update(float frameTime)
{
	for (int i = this->snake.size() - 1; i > 0; i--) {
		this->snake[i].SetSnakeSegmentPosition(this->snake[i - 1].GetSnakeSegmentPosition());
		this->snake[i].SetCurrentDirection(this->snake[i - 1].GetCurrentDirection());
	}
	
	switch (this->snake[0].GetCurrentDirection())
	{
	case LEFT:
		this->snake[0].SetSnakeSegmentPosition(GetSnakeHeadPosition() + sf::Vector2f(-1, 0) * this->speed);
		break;
	case RIGHT:
		this->snake[0].SetSnakeSegmentPosition(GetSnakeHeadPosition() + sf::Vector2f(1, 0) * this->speed);
		break;
	case UP:
		this->snake[0].SetSnakeSegmentPosition(GetSnakeHeadPosition() + sf::Vector2f(0, -1) * this->speed);
		break;
	case DOWN:
		this->snake[0].SetSnakeSegmentPosition(GetSnakeHeadPosition() + sf::Vector2f(0, 1) * this->speed);
		break;
	default:
		break;
	}
}

sf::Vector2f Snake::GetSnakeHeadPosition()
{
	return this->snake[0].GetSnakeSegmentPosition();
}

void Snake::IncrementTail()
{
	int lastSegmentIndex = this->snake.size() - 1;
	sf::Vector2f newSegmentPosition = this->snake[lastSegmentIndex].GetSnakeSegmentPosition();
	eDirection newSegmentDirection = this->snake[lastSegmentIndex].GetCurrentDirection();

	switch (newSegmentDirection) {
		case LEFT:
			newSegmentPosition.x += 10.0f;
			break;
		case RIGHT:
			newSegmentPosition.x -= 10.0f;
			break;
		case UP:
			newSegmentPosition.y += 10.0f;
			break;
		case DOWN:
			newSegmentPosition.y -= 10.0f;
			break;
		default:
			break;
	}
	
	SnakeSegment newSnakeSegment(newSegmentPosition, newSegmentDirection);
	this->snake.push_back(newSnakeSegment);
}

