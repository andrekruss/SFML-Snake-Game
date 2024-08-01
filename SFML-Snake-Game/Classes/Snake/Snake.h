#pragma once
#include <SFML/Graphics.hpp>

enum eDirection
{
	LEFT,
	UP,
	RIGHT,
	DOWN
};

class Snake
{
private:
	sf::RectangleShape snakeHead;
	float speed;
	eDirection currentDirection;

public:
	Snake(int windowWidth, int windowHeight);
	~Snake();
	void Setup();
	void Input();
	void Update(float frameTime);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetSnakeHeadPosition();
};