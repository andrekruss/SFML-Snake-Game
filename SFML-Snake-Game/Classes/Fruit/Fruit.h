#pragma once
#include <SFML/Graphics.hpp>
#include "../Snake/Snake.h"
#include "../../Enums/eFruitType.h"

class Fruit
{
private:
	sf::RectangleShape fruit;
	sf::Vector2f position;
	eFruitType type;

	sf::Vector2f GenerateRandomPosition(int windowWidth, int windowHeight, Snake snake);
	eFruitType GenerateFruitType();
public:
	Fruit();
	~Fruit();
	void Setup(int windowWidth, int windowHeight, Snake snake);
	void Draw(sf::RenderWindow& window);
	void Input();
	void Logic();
	sf::Vector2f GetFruitPosition();
	eFruitType GetFruitType();
	void RespawnFruit(int windowWidth, int windowHeight, Snake snake);
	void SetFruitColor();
};