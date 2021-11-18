#include "modele.h"
#include <iostream>
using namespace std;

int main() {
    timeInit();

    // Plateau plateau = {
    //     {8, 8, 12, 8},
    //     {8, 8, 256, 0},
    //     {8, 8, 2048, 8},
    //     {2048, 8, 8, 8},
    // };

    Plateau plateau = plateauInitial();

    while (1) {
        dessine(plateau);
        cout << "Enter direction :";
        char dir;
        cin >> dir;

        if (dir == 'i') plateau = deplacement(plateau, HAUT);
        if (dir == 'k') plateau = deplacement(plateau, BAS);
        if (dir == 'l') plateau = deplacement(plateau, DROITE);
        if (dir == 'j') plateau = deplacement(plateau, GAUCHE);
    }
    

    // vector<int> pos = randomPosition(plateau);

    // cout << "i= " << pos[0] << endl;
    // cout << "j= " << pos[1] << endl;

    // Plateau plateau = plateauInitial();

    // vector<vector<int>> column = {{2},
    //                               {2},
    //                               {2},
    //                               {0}};

    // vector<int> line = sumX({2, 2, 2, 2}, DROITE);

    // for (auto element : line) {
    //     cout << element << " | ";
    // }
    // cout << endl;

//     for (auto line : addRandomTile(plateau)) {
//         for (int element : line) {
//             cout << element << " ";
//         }
//         cout << endl;
//     }

    // dessine(plateau);

}
