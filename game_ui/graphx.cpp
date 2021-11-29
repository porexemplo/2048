#include "graphx.h"

sf::Clock animationTimer;

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

    sf::Text newGame;
    sf::Font font;
    if (!font.loadFromFile("ClearSans.ttf"))
        printf("Failed to load font\n");
    newGame.setFont(font);
    newGame.setStyle(sf::Text::Style::Bold);
    newGame.setFillColor(sf::Color(255, 255, 255));
    newGame.setString("Rejouer");
    sf::FloatRect floatrect = newGame.getLocalBounds();
    newGame.setPosition(xWIN - mCANVAS_ - xRESET + (xRESET - floatrect.width) * .5 - floatrect.left,
                        .575 * (yWIN - (CANVAS + mCANVAS_)) + (yRESET - floatrect.height) * .5 - floatrect.top
                       );
    newGame.setCharacterSize(.5 * yRESET);

    target.draw(newGame);
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

            sf::RectangleShape ScoreBox;
            ScoreBox.setSize(sf::Vector2f(xSCORE, ySCORE));
            ScoreBox.setPosition(xWIN - mCANVAS_ - xSCORE, (1 - .9) * CANVAS);
            ScoreBox.setFillColor(sf::Color(187, 173, 160));
            target.draw(ScoreBox);

            sf::Text ScoreText;
            ScoreText.setFont(font);
            ScoreText.setCharacterSize(.3 * ySCORE);
            ScoreText.setString("SCORE");
            floatrect = ScoreText.getLocalBounds();
            ScoreText.setPosition(xWIN - mCANVAS_ - xSCORE + (xSCORE - floatrect.width) * .5 - floatrect.left,
                              (1 - .9) * CANVAS
                             );
            ScoreText.setStyle(sf::Text::Style::Bold);
            target.draw(ScoreText);

            sf::Text ScoreValue;
            ScoreValue.setFont(font);
            ScoreValue.setCharacterSize(.5 * ySCORE);
            ScoreValue.setString(std::to_string(plateau.score));
            floatrect = ScoreValue.getLocalBounds();
            ScoreValue.setPosition(xWIN - mCANVAS_ - xSCORE + (xSCORE - floatrect.width) * .5 - floatrect.left,
                              (1 - .87) * CANVAS
                             );
            ScoreValue.setStyle(sf::Text::Style::Bold);
            target.draw(ScoreValue);
        }
    }

    // NOTE : this part is to add animations after each move

}

Plateau actOnEvent(sf::Event event, Plateau plateau) {
    sf::Keyboard::Key keyboardInput = event.key.code;

    if (event.type == sf::Event::KeyPressed) {
        // NOTE : i have no idea why keyboard input is inverted -> black magic :)
        switch (keyboardInput)
        {
        case sf::Keyboard::Left:
            return deplacement(plateau, HAUT);
        case sf::Keyboard::Right:
            return deplacement(plateau, BAS);
        case sf::Keyboard::Up:
            return deplacement(plateau, GAUCHE);
        case sf::Keyboard::Down:
            return deplacement(plateau, DROITE);
        
        default:
            return plateau;
        }
    }

    return plateau;
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
	case 256:
        return sf::Color(237, 204, 97);
	case 512:
        return sf::Color(237, 200, 80);
	case 1024:
        return sf::Color(237, 197, 63);
	case 2048:
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
