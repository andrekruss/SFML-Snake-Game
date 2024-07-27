#include "Map.h"

Map::Map(int windowWidth, int windowHeight)
{
	this->mapWidth = windowWidth;
	this->mapHeight = windowHeight;
}

Map::~Map()
{
}

void Map::Setup()
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < mapWidth; i++) {
		for (int j = 0; j < mapHeight; j++) {
			if (i == 0 || i == mapWidth - 10 || j == 0 || j == mapHeight - 10)
			{
				sf::RectangleShape rectangleShape;
				rectangleShape.setSize(sf::Vector2f(10.0f, 10.0f));
				rectangleShape.setFillColor(sf::Color::Red);
				rectangleShape.setPosition(sf::Vector2f((float) i, (float) j));
				window.draw(rectangleShape);
			}
		}
	}
}

void Map::Input()
{
}

void Map::Logic()
{
}

