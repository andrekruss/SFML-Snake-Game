#pragma once
#include <SFML/Graphics.hpp>

class GameOverScreen
{
private:
	sf::Text gameOverText;
	sf::Text finalScoreText;
	sf::Font font;
public:
	GameOverScreen();
	~GameOverScreen();
	void Setup(int windowWidth, int windowHeight);
	void Input();
	void Update();
	void Draw(sf::RenderWindow& window, int finalScore);
};