#include <iostream>
#include "modele.h"

using namespace std;

void refreshConsole() {
#if defined _WIN32 // preprocessor directive
    //clrscr(); // include conio.h
    system("cls");
#elif defined (__linux__) || defined(__gnu_linux__) || defined(__LINUX__) || defined(__APPLE__)
    // system("clear");
    cout << "\x1B[2J\x1B[H";
#endif
}

Plateau playTurn(Plateau plateau, int iterr) {
    Plateau newPlateau = deplacement(plateau, HAUT);
    if (newPlateau != plateau and iterr % 2) return newPlateau;

    newPlateau = deplacement(plateau, DROITE);
    if (newPlateau != plateau and not iterr % 2) return newPlateau;

    newPlateau = deplacement(plateau, GAUCHE);
    if (newPlateau != plateau) return newPlateau;

    newPlateau = deplacement(plateau, BAS);
    if (newPlateau != plateau) return newPlateau;

    return plateau;
}

int main() {
    timeInit();
    refreshConsole();

    Plateau plateau = plateauInitial();

    while(1) {
        int iterr = 0;
        cout << dessine(plateau);
        plateau = playTurn(plateau, iterr);
        iterr++;
        refreshConsole();
    }

    return 0;
}
