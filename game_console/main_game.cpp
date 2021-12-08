/**
 * @file main_game.cpp
 * @authors redwane, asma
 * @brief main script, takes input and renders game to console
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "modele.h"

/**
 * @brief refreshes console based on OS
 * 
 */
void refreshConsole() {
#if defined _WIN32 // preprocessor directive
    system("cls");
#elif defined (__linux__) || defined(__gnu_linux__) || defined(__LINUX__) || defined(__APPLE__)
    // system("clear");
    cout << "\x1B[2J\x1B[H";
#endif
}

int main() {
    // verify whether on windows
    if (! inSystem) {
        refreshConsole();
        std::cout << "modify while loop before compiling in linux / mac";
        return 0;
    }
    refreshConsole();
    timeInit();

    Plateau plateau = plateauInitial();
    cout << dessine(plateau);

    while(not estTermine(plateau)) {
        string dir;
        cout << "\nUse arrow keys to navigate, press q to quit\n";
        
        int userInput = 0;

        switch((userInput = getch())) {
            case UP:
                plateau = deplacement(plateau, HAUT);
                break;
            case DOWN:
                plateau = deplacement(plateau, BAS);
                break;
            case LEFT:
                plateau = deplacement(plateau, GAUCHE);
                break;
            case RIGHT:
                plateau = deplacement(plateau, DROITE);
                break;
            case 113:
                break;
        }

        refreshConsole();
        if (userInput == 113) break;
        cout << dessine(plateau);
    }
}
