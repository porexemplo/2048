#include "modele.h"
#include <iostream>
using namespace std;

int main() {
    timeInit();

    Plateau plateau = {
        {8, 8, 8, 8},
        {8, 8, 8, 0},
        {8, 8, 8, 8},
        {0, 8, 8, 8},
    };

    // vector<int> pos = randomPosition(plateau);

    // cout << "i= " << pos[0] << endl;
    // cout << "j= " << pos[1] << endl;

    // Plateau plateau = plateauInitial();

    // vector<vector<int>> column = {{2},
    //                               {2},
    //                               {2},
    //                               {0}};

    vector<int> line = sumX({2, 2, 2, 2}, DROITE);

    for (auto element : line) {
        cout << element << " | ";
    }
    cout << endl;

    // for (auto line : sumY(column, HAUT)) {
    //     for (int element : line) {
    //         cout << element << " ";
    //     }
    //     cout << endl;
    // }
}
