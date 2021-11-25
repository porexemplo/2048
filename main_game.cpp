#include "modele.h"
#include <iostream>
using namespace std;

// TODO write documentation
void refreshConsole() {
#if defined _WIN32 // preprocessor directive
    //clrscr(); // include conio.h
    system("cls");
#elif defined (__linux__) || defined(__gnu_linux__) || defined(__LINUX__) || defined(__APPLE__)
    // system("clear");
    cout << "\x1B[2J\x1B[H";
#endif
}

int main() {
    refreshConsole();
    timeInit();

    Plateau plateau = plateauInitial();
    cout << dessine(plateau);

    while(not estTermine(plateau)) {
        string dir;
        cout << "Entrer dir : ";
        cin >> dir;
        if (dir == "l") {
            plateau = deplacement(plateau, DROITE);
        }
        if (dir == "j") {
            plateau = deplacement(plateau, GAUCHE);
        }
        if (dir == "i") {
            plateau = deplacement(plateau, HAUT);
        }
        if (dir == "k") {
            plateau = deplacement(plateau, BAS);
        }
        refreshConsole();
        cout << dessine(plateau);
    }
}
