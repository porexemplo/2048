#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>
#include "setup.h"
#include "modele.h"
#include <string>

sf::Clock animationTimer;

void renderLayout(sf::RenderTarget& target);
void renderGrid(Plateau grid, sf::RenderTarget& target);

Plateau actOnEvent(sf::Event event, Plateau plateau);

sf::Color getTileColor(int value);

sf::Color getTextColor(int value);
int getTextSize(int value);