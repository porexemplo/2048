#include "graphx.h"

int main() {

    Plateau plateau = {{2, 0, 2, 2048},
                       {128, 8, 16, 4},
                       {0, 0, 32, 4},
                       {2, 4, 64, 32}};

    sf::RenderWindow window(sf::VideoMode(xWIN, yWIN), "Tiles", sf::Style::Titlebar | sf::Style::Close);

    sf::Event event;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(250, 248, 239));
        renderLayout(window);
        renderGrid(plateau, window);
        window.display();
    }

    return 0;
}