#pragma once
#include <string>

class Color {
public:
    int foreground;
    int background;
};

const int BOLD = 1,
          NORMAL = 2,
          ITALIC = 3;


/**
 * @brief attribue à chaque couleur (foreground & background) son code (un entier) 
 */
void declare_colors();

/**
 * @param format int parmis (1, 2, 3) = (BOLD, NORMAL, ITALIC)
 * @param bg_color Color représente la couleur de la case
 * @param fg_color Color représente la couleur de l'entier
 * @return std::string échappement ANSI représentant les couleurs e.g. "\033[2;32;38m"
 */
std::string format_color(int format, Color bg_color, Color fg_color);

/**
 * @brief attribue une couleur à value
 * 
 * @param value int puissance de 2
 * @return std::string échappenent ANSI représentant la couleur attribuée à value
 */
std::string get_color_of(int value);
