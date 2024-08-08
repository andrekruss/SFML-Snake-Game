#include "GameOverScreen.h"
#include <iostream>
#include <SFML/Graphics.hpp>

GameOverScreen::GameOverScreen()
{
}

GameOverScreen::~GameOverScreen()
{
}

void GameOverScreen::Setup(int windowWidth, int windowHeight)
{
    if (!this->font.loadFromFile("assets/fonts/arial.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
    }
    else
    {
        this->gameOverText.setFont(this->font);
        std::string gameOverText = "GAME OVER!";
        this->gameOverText.setString(gameOverText);
        this->gameOverText.setPosition(sf::Vector2f((float) windowWidth / 4, (float) windowHeight / 4));

        this->finalScoreText.setFont(this->font);
        this->finalScoreText.setPosition(this->gameOverText.getPosition() + sf::Vector2f(50.0f, 50.0f));
    }
}

void GameOverScreen::Input()
{
}

void GameOverScreen::Update()
{
}

void GameOverScreen::Draw(sf::RenderWindow& window, int finalScore)
{
    this->finalScoreText.setString("Score: " + std::to_string(finalScore));
    window.draw(this->gameOverText);
    window.draw(this->finalScoreText);
}
