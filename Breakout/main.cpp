#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <iostream>

#include "states.h"

int main()
{
    

    sf::RenderWindow window(sf::VideoMode(1000, 800), "Breakout");

    sf::View view(sf::FloatRect(0, 0, 1000, 800));
    window.setView(view);

    GameManager gameManager(&window,&view);
    gameManager.initialize();

    sf::Clock clock;
    float deltaTime;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        deltaTime = clock.restart().asSeconds();

        window.setSize(sf::Vector2u(1000, 800));

            gameManager.update(deltaTime);
            window.clear();
            gameManager.render();
            window.display();
    }

    return 0;
}
