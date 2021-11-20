#include "modele.h"
#include <iostream>
using namespace std;

int main() {
    timeInit();

    Plateau plateau = plateauInitial();
    cout << dessine(plateau);

    while(not estTermine(plateau) or not estGagnant(plateau)) {
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
        cout << dessine(plateau);
    }

}
