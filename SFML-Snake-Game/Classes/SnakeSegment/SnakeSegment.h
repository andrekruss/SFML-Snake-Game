#pragma once
#include <SFML/Graphics.hpp>
#include "../../Enums/eDirection.h"

class SnakeSegment
{
private:
	sf::RectangleShape snakeSegment;
	eDirection currentDirection;
public:
	SnakeSegment(sf::Vector2f snakeSegmentPosition, eDirection direction);
	~SnakeSegment();
	void SetSnakeSegmentPosition(sf::Vector2f position);
	sf::Vector2f GetSnakeSegmentPosition();
	void SetCurrentDirection(eDirection direction);
	eDirection GetCurrentDirection();
	sf::RectangleShape GetSnakeSegment();
};