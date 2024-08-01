#include <SFML/Graphics.hpp>
#include "Classes/Map/Map.h"
#include "Classes/Snake/Snake.h"
#include "Classes/Fruit/Fruit.h"
#include "Classes/GameManager/GameManager.h"

int main()
{
    int windowWidth = 800, windowHeight = 600;
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
    sf::Time timer;
    double frameTime;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (!gameManager.CheckGameOver())
        {

            timer = clock.restart();
            frameTime = timer.asMilliseconds() / 1000.0;

            snake.Input();
            gameManager.CheckMapBorderCollision(windowWidth, windowHeight, snake.GetSnakeHeadPosition());
            snake.Update((float)frameTime);

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

    return 0;
}