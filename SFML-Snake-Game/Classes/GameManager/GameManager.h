#pragma once
#include <SFML/Graphics.hpp>
#include "../Snake/Snake.h"

class GameManager
{
private:
	bool isGameOver;
	bool isGamePaused;
	int score;
public:
	GameManager();
	~GameManager();
	void Input();
	bool CheckGameOver();
	void CheckMapBorderCollision(int mapWidth, int mapHeight, sf::Vector2f snakeHeadPosition);
	bool CheckSnakeFruitCollision(sf::Vector2f snakeHeadPosition, sf::Vector2f fruitPosition);
	void CheckSnakeSelfCollision(Snake snake);
	int GetScore();
	bool CheckGamePauseStatus();
};
