#pragma once
#include <SFML/Graphics.hpp>

class GameManager
{
private:
	bool isGameOver;
	int score;
public:
	GameManager();
	~GameManager();
	bool CheckGameOver();
	void CheckMapBorderCollision(int mapWidth, int mapHeight, sf::Vector2f snakeHeadPosition);
};
