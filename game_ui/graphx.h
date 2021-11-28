#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>
#include "setup.h"
#include "modele.h"
#include <string>


void renderLayout(sf::RenderTarget& target);
void renderGrid(Plateau grid, sf::RenderTarget& target);

sf::Color getTileColor(int value);

sf::Color getTextColor(int value);
int getTextSize(int value);