#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "modele.h"

using namespace std;

Plateau plateauVide() {
	Plateau plaVide (4);
	for (int i = 0; i < 4; i++) {
		plaVide[i] = vector<int>(4);
	}
	return plaVide;
}

int randomPosition(int maxInt) {
	srand ((unsigned)time(0));
	 return (rand()%maxInt);
}
