#include "Fruit.h"
#include <time.h>

Fruit::Fruit(int windowWidth, int windowHeight)
{
	srand(time(0));
	int xLowerLimit = 10;
	int xUpperLimit = windowWidth - 20;
	int yLowerLimit = 10;
	int yUpperLimit = windowHeight - 20;
	int x = (rand() % (xUpperLimit - xLowerLimit + 1)) + xLowerLimit;
	int y = (rand() % (yUpperLimit - yLowerLimit + 1)) + yLowerLimit;
	this->fruit = sf::RectangleShape();
	this->fruit.setSize(sf::Vector2f(10.0f, 10.0f));
	this->fruit.setFillColor(sf::Color::Yellow);
	this->fruit.setPosition(sf::Vector2f(x, y));
}

Fruit::~Fruit()
{
}

void Fruit::Setup()
{
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
