#include "GameManager.h"

GameManager::GameManager()
{
	this->isGameOver = false;
	this->score = 0;
}

GameManager::~GameManager()
{
}

bool GameManager::CheckGameOver()
{
	return isGameOver;
}

void GameManager::CheckMapBorderCollision(int mapWidth, int mapHeight, sf::Vector2f snakeHeadPosition)
{
	if (snakeHeadPosition.x > mapWidth - 10 || snakeHeadPosition.x < 10) {
		this->isGameOver = true;
		return;
	}
	if (snakeHeadPosition.y > mapHeight - 10 || snakeHeadPosition.y < 10) {
		this->isGameOver = true;
		return;
	}
}

bool GameManager::CheckSnakeFruitCollision(sf::Vector2f snakeHeadPosition, sf::Vector2f fruitPosition)
{
	if (snakeHeadPosition.x == fruitPosition.x && snakeHeadPosition.y == fruitPosition.y) {
		this->score += 10;
		return true;
	}
	return false;
}

int GameManager::GetScore()
{
	return this->score;
}
