#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../../Enums/eDirection.h"
#include "../SnakeSegment/SnakeSegment.h"

class Snake
{
private:
	std::vector<SnakeSegment> snake;
	float speed;

public:
	Snake(int windowWidth, int windowHeight);
	~Snake();
	void Setup();
	void Input();
	void Update();
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetSnakeHeadPosition();
	void IncrementTail();
};