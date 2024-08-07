#pragma once
#include <SFML/Graphics.hpp>
#include "../Snake/Snake.h"
#include "../Fruit/Fruit.h"

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
	bool CheckSnakeFruitCollision(Snake snake, Fruit fruit);
	void CheckSnakeSelfCollision(Snake snake);
	int GetScore();
	bool CheckGamePauseStatus();
};
