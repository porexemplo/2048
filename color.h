#pragma once
#include <string>

class Color {
public:
    int foreground;
    int background;
};

const int Bold = 1,
          Normal = 2,
          Italic = 3;


void declare_colors();

std::string format_color(int format, Color bg_color, Color fg_color);

std::string get_color_of(int value);
