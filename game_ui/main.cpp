#include "graphx.h"

int main() {

    Plateau plateau = {{2, 0, 2, 2048},
                       {128, 8, 16, 4},
                       {0, 0, 32, 4},
                       {2, 4, 64, 32}};

    // Plateau plateau = plateauInitial();

    sf::RenderWindow window(sf::VideoMode(xWIN, yWIN), "Tiles", sf::Style::Titlebar | sf::Style::Close);

    sf::Event event;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            Plateau newPlateau = actOnEvent(event, plateau);
            if (plateau != newPlateau) {
                plateau = newPlateau;
                break;
            }
        }

        window.clear(sf::Color(250, 248, 239));
        renderLayout(window);
        renderGrid(plateau, window);
        window.display();
    }

    return 0;
}