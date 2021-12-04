#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>
#include "setup.h"
#include "modele.h"
#include <string>

std::vector<std::pair<std::pair<sf::Vector2i, sf::Vector2i>, char>> moves;

void renderLayout(sf::RenderTarget& target);
void renderGrid(Plateau grid, sf::RenderTarget& target);

Plateau actOnEvent(sf::Event event, Plateau plateau);

sf::Color getTileColor(int value);

sf::Color getTextColor(int value);
int getTextSize(int value);