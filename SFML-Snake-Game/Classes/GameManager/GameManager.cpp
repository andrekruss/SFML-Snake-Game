#include "GameManager.h"

GameManager::GameManager()
{
	this->isGameOver = false;
	this->isGamePaused = false;
	this->score = 0;
}

GameManager::~GameManager()
{
}

void GameManager::Input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && !this->isGamePaused) {
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
			this->isGamePaused = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && this->isGamePaused) {
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
			this->isGamePaused = false;
		}
	}
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

void GameManager::CheckSnakeSelfCollision(Snake snake)
{
	sf::Vector2f snakeHeadPosition = snake.GetSnakeHeadPosition();
	for (int i = 1; i < snake.GetSnakeSize(); i++) {
		sf::Vector2f segmentPosition = snake.GetSnakeSegment(i).GetSnakeSegmentPosition();
		if (snakeHeadPosition.x == segmentPosition.x && snakeHeadPosition.y == segmentPosition.y) {
			this->isGameOver = true;
			return;
		}
	}
}

int GameManager::GetScore()
{
	return this->score;
}

bool GameManager::CheckGamePauseStatus()
{
	return this->isGamePaused;
}
