#include "SnakeSegment.h"

SnakeSegment::SnakeSegment(sf::Vector2f snakeSegmentPosition, eDirection direction)
{
	this->snakeSegment = sf::RectangleShape();
	this->snakeSegment.setSize(sf::Vector2f(10.0f, 10.0f));
	this->snakeSegment.setFillColor(sf::Color::Green);
	this->snakeSegment.setPosition(snakeSegmentPosition);
	this->currentDirection = direction;
}

SnakeSegment::~SnakeSegment()
{
}

void SnakeSegment::SetSnakeSegmentPosition(sf::Vector2f position)
{
	this->snakeSegment.setPosition(position);
}

sf::Vector2f SnakeSegment::GetSnakeSegmentPosition()
{
	return this->snakeSegment.getPosition();
}

void SnakeSegment::SetCurrentDirection(eDirection direction)
{
	this->currentDirection = direction;
}

eDirection SnakeSegment::GetCurrentDirection()
{
	return this->currentDirection;
}

sf::RectangleShape SnakeSegment::GetSnakeSegment()
{
	return this->snakeSegment;
}
