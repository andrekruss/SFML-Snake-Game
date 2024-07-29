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
	sf::Vector2f currentPosition;
	float speed;
	eDirection currentDirection;

public:
	Snake(int windowWidth, int windowHeight);
	~Snake();
	void Setup();
	void Draw(sf::RenderWindow& window);
	void Input();
	void Logic();
};