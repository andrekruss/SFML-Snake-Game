#pragma once
#include <SFML/Graphics.hpp>

class Snake
{
private:
	sf::RectangleShape snakeHead;
	sf::Vector2f currentPosition;

public:
	Snake(int windowWidth, int windowHeight);
	~Snake();
	void Setup();
	void Draw(sf::RenderWindow& window);
	void Input();
	void Logic();
};