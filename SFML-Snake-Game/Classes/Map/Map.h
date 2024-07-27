#pragma once
#include <SFML/Graphics.hpp>

class Map
{
private:
	int mapWidth;
	int mapHeight;

public:
	Map(int windowWidth, int windowHeight);
	~Map();
	void Setup();
	void Draw(sf::RenderWindow& window);
	void Input();
	void Logic();
};