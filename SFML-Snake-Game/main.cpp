#include <SFML/Graphics.hpp>
#include <iostream>
#include "Classes/Map/Map.h"
#include "Classes/Snake/Snake.h"
#include "Classes/Fruit/Fruit.h"
#include "Classes/GameManager/GameManager.h"
#include "Classes/GameOverScreen/GameOverScreen.h"

int main()
{
    int windowWidth = 400, windowHeight = 400;
    sf::RenderWindow window(
        sf::VideoMode(windowWidth, windowHeight), 
        "Snaaaake!", 
        sf::Style::Default
    );
    window.setFramerateLimit(60);

    Map map(windowWidth, windowHeight);
    Snake snake(windowWidth, windowHeight);
    Fruit fruit;
    GameManager gameManager;
    GameOverScreen gameOverScreen;
    fruit.Setup(windowWidth, windowHeight, snake);
    gameOverScreen.Setup(windowWidth, windowHeight);

    int normalFruitScore = 10;
    int superFruitScore = 50;

    sf::Clock clock;
    int moveInterval = 75;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (gameManager.CheckGameOver()) {
            window.clear(sf::Color::Black);
            gameOverScreen.Draw(window, gameManager.GetScore());
            window.display();
            continue;
        }

        gameManager.Input();

        if (gameManager.CheckGamePauseStatus())
            continue;

        snake.Input();

        if (clock.getElapsedTime().asMilliseconds() >= moveInterval) {
            snake.Update();
            clock.restart();
        }

        gameManager.CheckSnakeSelfCollision(snake);
        gameManager.CheckMapBorderCollision(windowWidth, windowHeight, snake.GetSnakeHeadPosition());
       
        if (gameManager.CheckSnakeFruitCollision(snake, fruit)) {
            fruit.RespawnFruit(windowWidth, windowHeight, snake);
            snake.IncrementTail();
        }

        window.clear(sf::Color::Black);
        snake.Draw(window);
        fruit.Draw(window);
        map.Draw(window);
        window.display();
    }

    std::cout << "Snake last position: " << snake.GetSnakeHeadPosition().x << " " << snake.GetSnakeHeadPosition().y << std::endl;
    std::cout << "Score = " << gameManager.GetScore() << std::endl;

    return 0;
}