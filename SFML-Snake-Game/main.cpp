#include <SFML/Graphics.hpp>
#include <iostream>
#include "Classes/Map/Map.h"
#include "Classes/Snake/Snake.h"
#include "Classes/Fruit/Fruit.h"
#include "Classes/GameManager/GameManager.h"

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
    Fruit fruit(windowWidth, windowHeight);
    GameManager gameManager;

    sf::Clock clock;
    int moveInterval = 75;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        gameManager.CheckSnakeSelfCollision(snake);
        gameManager.CheckMapBorderCollision(windowWidth, windowHeight, snake.GetSnakeHeadPosition());
        if (gameManager.CheckSnakeFruitCollision(snake.GetSnakeHeadPosition(), fruit.GetFruitPosition())) {
            fruit.RespawnFruit(windowWidth, windowHeight);
            snake.IncrementTail();
        }

        gameManager.Input();

        if (gameManager.CheckGamePauseStatus())
            continue;

        if (!gameManager.CheckGameOver())
        {
            snake.Input();

            if (clock.getElapsedTime().asMilliseconds() >= moveInterval) {
                snake.Update();
                clock.restart();
            }

            window.clear(sf::Color::Black);
            snake.Draw(window);
            fruit.Draw(window);
            map.Draw(window);
            window.display();
        }
        else {
            break;
        }
    }

    std::cout << "Snake last position: " << snake.GetSnakeHeadPosition().x << " " << snake.GetSnakeHeadPosition().y << std::endl;
    std::cout << "Score = " << gameManager.GetScore() << std::endl;

    return 0;
}