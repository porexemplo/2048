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

    for (auto line : addRandomTile(plateau)) {
        for (int element : line) {
            cout << element << " ";
        }
        cout << endl;
    }
}
