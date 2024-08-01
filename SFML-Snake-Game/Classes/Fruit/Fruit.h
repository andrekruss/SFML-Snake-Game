#pragma once
#include <SFML/Graphics.hpp>

class Fruit
{
private:
	sf::RectangleShape fruit;
	sf::Vector2f position;

	sf::Vector2f generateRandomPosition(int windowWidth, int windowHeight);
public:
	Fruit(int windowWidth, int windowHeight);
	~Fruit();
	void Setup();
	void Draw(sf::RenderWindow& window);
	void Input();
	void Logic();
};