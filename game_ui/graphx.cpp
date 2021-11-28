#include "graphx.h"

void renderLayout(sf::RenderTarget& target) {
    sf::RectangleShape Canvas;
    Canvas.setSize(sf::Vector2f(CANVAS, CANVAS));
    Canvas.setPosition(mCANVAS_, yWIN - (CANVAS + mCANVAS_));
    Canvas.setFillColor(sf::Color(187, 173, 160));

    target.draw(Canvas);

    sf::RectangleShape Reset;
    Reset.setSize(sf::Vector2f(xRESET, yRESET));
    Reset.setPosition(xWIN - mCANVAS_ - xRESET, .575 * (yWIN - (CANVAS + mCANVAS_)));
    Reset.setFillColor(sf::Color(143, 122, 102));

    target.draw(Reset);
}

void renderGrid(Plateau plateau, sf::RenderTarget& target) {
    sf::RectangleShape Tile;
    Tile.setSize(sf::Vector2f(TILE, TILE));

    sf::Text TileOutput;
    sf::Font font;
    if (!font.loadFromFile("ClearSans.ttf"))
			printf("Failed to load font\n");
    TileOutput.setFont(font);
    TileOutput.setStyle(sf::Text::Style::Bold);
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            Tile.setFillColor(getTileColor(plateau[i][j]));
            Tile.setPosition(
                (mCANVAS_ + mTILE_ + i * (mTILE_ + TILE)),
                (yWIN - (CANVAS + mCANVAS_) + mTILE_ + j * (mTILE_ + TILE))
            );
            target.draw(Tile);

            TileOutput.setCharacterSize(getTextSize(plateau[i][j]));
            TileOutput.setFillColor(getTextColor(plateau[i][j]));
            TileOutput.setString(plateau[i][j] ? std::to_string(plateau[i][j]) : "");
            sf::FloatRect floatrect = TileOutput.getLocalBounds();
            TileOutput.setPosition(
                (mCANVAS_ + mTILE_ + i * (mTILE_ + TILE)) + (TILE - floatrect.width) / 2 - floatrect.left,
                (yWIN - (CANVAS + mCANVAS_) + mTILE_ + j * (mTILE_ + TILE)) + (TILE - floatrect.height) / 2 - floatrect.top
                );
            target.draw(TileOutput);
        }
    }
}

sf::Color getTileColor(int value) {
    switch (value) {
    case 2:
        return sf::Color(238, 228, 218);
	case 4:
        return sf::Color(237, 224, 200);
	case 8:
        return sf::Color(242, 177, 121);
	case 16:
        return sf::Color(245, 149, 99);
	case 32:
        return sf::Color(246, 124, 95);
	case 64:
        return sf::Color(246, 94, 59);
	case 128:
        return sf::Color(237, 207, 114);
	case 512:
        return sf::Color(237, 204, 97);
	case 1024:
        return sf::Color(237, 200, 80);
	case 2048:
        return sf::Color(237, 197, 63);
	case 4096:
        return sf::Color(237, 194, 46);
    default:
        return sf::Color(205, 193, 180);
    }
}

sf::Color getTextColor(int value) {
    if (value >= 8) return sf::Color(249, 246, 242);
    return sf::Color(119, 110, 101);
}

// TODO : ratio the hell out of it
int getTextSize(int value) {
    return .8 * (
    value < 10 ? .6 * TILE : (
        value < 100 ? .58 * TILE : (
            value < 1000 ? .45 * TILE : .38 * TILE
        )
    ));
}
