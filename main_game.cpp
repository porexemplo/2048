#include "modele.h"
#include <iostream>
using namespace std;

int main() {
    timeInit();

    Plateau plateau = plateauVide();
    plateau = addRandomTile(plateau);

    for (auto line : plateau) {
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
