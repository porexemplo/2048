#include "modele.h"
#include <iostream>
using namespace std;

int main() {
    Plateau plateau = {
        {0, 2, 4, 8},
        {2, 2, 2, 2},
        {0, 0, 2, 4},
        {2, 0, 2, 8},
    };

    for (auto line : deplacementGauche(plateau)) {
        for (int element : line) {
            cout << element << " ";
        }
        cout << endl;
    }

    // vector<int> line = {2, 2, 2, 2};
    // line = organizeLeft(line);
    // for (int element : line)
    //     cout << element << " ";
    return 0;
}
