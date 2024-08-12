#include "Fruit.h"
#include "../Snake/Snake.h"
#include <time.h>
#include <iostream>	

sf::Vector2f Fruit::GenerateRandomPosition(int windowWidth, int windowHeight, Snake snake)
{
	srand(time(0));
	int xLowerLimit = 1;
	int xUpperLimit = (windowWidth - 20) / 10;
	int yLowerLimit = 1;
	int yUpperLimit = (windowHeight - 20) / 10;

	while (true) {

		int x = ((rand() % (xUpperLimit - xLowerLimit + 1)) + xLowerLimit) * 10;
		int y = ((rand() % (yUpperLimit - yLowerLimit + 1)) + yLowerLimit) * 10;
		bool validSpawnPosition = true;

		for (int i = 0; i < snake.GetSnakeSize(); i++) {
			sf::Vector2f snakeSegmentPosition = snake.GetSnakeSegment(i).GetSnakeSegmentPosition();
			if (snakeSegmentPosition.x == x && snakeSegmentPosition.y == y) {
				validSpawnPosition = false;
				break;
			}
		}

		if (!validSpawnPosition)
			continue;

		return sf::Vector2f(x, y);
	}
}

eFruitType Fruit::GenerateFruitType()
{
	srand(time(0));
	int randomValue = rand() % 20 + 1;
	if (randomValue == 1)
		return eFruitType::SUPER;
	return eFruitType::NORMAL;
}

Fruit::Fruit()
{
}

Fruit::~Fruit()
{
}

void Fruit::Setup(int windowWidth, int windowHeight, Snake snake)
{
	this->fruit = sf::RectangleShape();
	this->fruit.setSize(sf::Vector2f(10.0f, 10.0f));
	this->type = GenerateFruitType();
	SetFruitColor();
	this->fruit.setPosition(GenerateRandomPosition(windowWidth, windowHeight, snake));
	std::cout << "Current Fruit position: " << this->fruit.getPosition().x << " " << this->fruit.getPosition().y << std::endl;
}

void Fruit::Draw(sf::RenderWindow& window)
{
	window.draw(this->fruit);
}

void Fruit::Input()
{
}

void Fruit::Logic()
{
}

sf::Vector2f Fruit::GetFruitPosition()
{
	return this->fruit.getPosition();
}

eFruitType Fruit::GetFruitType()
{
	return this->type;
}

void Fruit::RespawnFruit(int windowWidth, int windowHeight, Snake snake)
{
	this->fruit.setPosition(GenerateRandomPosition(windowWidth, windowHeight, snake));
	this->type = GenerateFruitType();
	SetFruitColor();
}

void Fruit::SetFruitColor()
{
	if (this->type == eFruitType::NORMAL)
		this->fruit.setFillColor(sf::Color::Yellow);
	else if (this->type == eFruitType::SUPER)
		this->fruit.setFillColor(sf::Color::Magenta);
}
