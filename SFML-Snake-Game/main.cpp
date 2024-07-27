#include <SFML/Graphics.hpp>
#include "Classes/Map/Map.h"
#include "Classes/Snake/Snake.h"

int main()
{
    int windowWidth = 800, windowHeight = 600;
    sf::RenderWindow window(
        sf::VideoMode(windowWidth, windowHeight), 
        "Snaaaake!", 
        sf::Style::Default
    );

    Map map(windowWidth, windowHeight);
    Snake snake(windowWidth, windowHeight);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        snake.Draw(window);
        map.Draw(window);
        window.display();
    }

    return 0;
}