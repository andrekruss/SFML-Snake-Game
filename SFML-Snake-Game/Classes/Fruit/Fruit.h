#pragma once
#include <SFML/Graphics.hpp>
#include "../../Enums/eFruitType.h"

class Fruit
{
private:
	sf::RectangleShape fruit;
	sf::Vector2f position;
	eFruitType type;

	sf::Vector2f GenerateRandomPosition(int windowWidth, int windowHeight);
	eFruitType GenerateFruitType();
public:
	Fruit(int windowWidth, int windowHeight);
	~Fruit();
	void Setup();
	void Draw(sf::RenderWindow& window);
	void Input();
	void Logic();
	sf::Vector2f GetFruitPosition();
	eFruitType GetFruitType();
	void RespawnFruit(int windowWidth, int windowHeight);
	void SetFruitColor();
};