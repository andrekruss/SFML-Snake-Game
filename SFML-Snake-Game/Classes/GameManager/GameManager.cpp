#include "GameManager.h"
#include "../../Enums/eFruitType.h"

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

bool GameManager::CheckMapBorderCollision(int mapWidth, int mapHeight, sf::Vector2f snakeHeadPosition)
{
	if (snakeHeadPosition.x >= mapWidth - 10 || snakeHeadPosition.x < 10) {
		this->isGameOver = true;
		return true;
	}
	if (snakeHeadPosition.y >= mapHeight - 10 || snakeHeadPosition.y < 10) {
		this->isGameOver = true;
		return true;
	}
	return false;
}

bool GameManager::CheckSnakeFruitCollision(Snake snake, Fruit fruit)
{
	sf::Vector2f snakeHeadPosition = snake.GetSnakeHeadPosition();
	sf::Vector2f fruitPosition = fruit.GetFruitPosition();
	if (snakeHeadPosition.x == fruitPosition.x && snakeHeadPosition.y == fruitPosition.y) {
		eFruitType fruitType = fruit.GetFruitType();
		if (fruitType == eFruitType::NORMAL)
			this->score += 10;
		else if (fruitType == eFruitType::NORMAL)
			this->score += 50;
		return true;
	}
	return false;
}

bool GameManager::CheckSnakeSelfCollision(Snake snake)
{
	sf::Vector2f snakeHeadPosition = snake.GetSnakeHeadPosition();
	for (int i = 1; i < snake.GetSnakeSize(); i++) {
		sf::Vector2f segmentPosition = snake.GetSnakeSegment(i).GetSnakeSegmentPosition();
		if (snakeHeadPosition.x == segmentPosition.x && snakeHeadPosition.y == segmentPosition.y) {
			this->isGameOver = true;
			return true;
		}
	}
	return false;
}

int GameManager::GetScore()
{
	return this->score;
}

bool GameManager::CheckGamePauseStatus()
{
	return this->isGamePaused;
}
