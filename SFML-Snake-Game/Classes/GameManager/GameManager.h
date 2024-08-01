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
	bool CheckSnakeFruitCollision(sf::Vector2f snakeHeadPosition, sf::Vector2f fruitPosition);
	int GetScore();
};
