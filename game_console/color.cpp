#include <string>
#include <sstream>
#include "color.h"

Color Black,
      Red,
      Green,
      Yellow,
      Blue,
      Magenta,
      Cyan,
      White,
      Bright_Black,
      Bright_Red,
      Bright_Green,
      Bright_Yellow,
      Bright_Blue,
      Bright_Magenta,
      Bright_Cyan,
      Bright_White;

void declare_colors() {
    Black.foreground = 30;
    Black.background = 40;

    Red.foreground = 31;
    Red.background = 41;

    Green.foreground = 32;
    Green.background = 42;

    Yellow.foreground = 33;
    Yellow.background = 43;

    Blue.foreground = 34;
    Blue.background = 44;

    Magenta.foreground = 35;
    Magenta.background = 45;

    Cyan.foreground = 36;
    Cyan.background = 46;

    White.foreground = 37;
    White.background = 47;

    Bright_Black.foreground = 90;
    Bright_Black.background = 100;

    Bright_Red.foreground = 91;
    Bright_Red.background = 101;

    Bright_Green.foreground = 92;
    Bright_Green.background = 102;

    Bright_Yellow.foreground = 93;
    Bright_Yellow.background = 103;

    Bright_Blue.foreground = 94;
    Bright_Blue.background = 104;

    Bright_Magenta.foreground = 95;
    Bright_Magenta.background = 105;

    Bright_Cyan.foreground = 96;
    Bright_Cyan.background = 106;

    Bright_White.foreground = 97;
    Bright_White.background = 107;
}


std::string format_color(int format, Color bg_color, Color fg_color) {
    declare_colors();
    std::ostringstream flux;
    flux << "\033[" << format << ";"
         << bg_color.background << ";"
         << fg_color.foreground << "m";
    return flux.str();
}

std::string get_color_of(int value) {
    declare_colors();
    Color bg_color,
          fg_color;

    switch (value) {
    case 2:
        bg_color = Bright_Black;
        fg_color = Bright_White;
        break;
    
    case 4:
        bg_color = Green;
        fg_color = Bright_White;
        break;
    
    case 8:
        bg_color = Bright_Red;
        fg_color = Bright_White;
        break;
    
    case 16:
        bg_color = Cyan;
        fg_color = Bright_White;
        break;
    
    case 32:
        bg_color = Magenta;
        fg_color = Bright_White;
        break;
    
    case 64:
        bg_color = Blue;
        fg_color = Bright_White;
        break;
    
    case 128:
        bg_color = Bright_Yellow;
        fg_color = Bright_Black;
        break;
    
    case 256:
        bg_color = Red;
        fg_color = Bright_White;
        break;
    
    case 512:
        bg_color = Yellow;
        fg_color = Black;
        break;
    
    case 1024:
        bg_color = Bright_Magenta;
        fg_color = Bright_White;
        break;
    
    case 2048:
        bg_color = Bright_Green;
        fg_color = Bright_Black;
        break;
    
    default:
        return "";
    }

    return format_color(NORMAL, bg_color, fg_color);
}
