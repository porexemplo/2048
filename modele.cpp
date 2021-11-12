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
		plaVide[i] = {0, 0, 0, 0};
	}
	return plaVide;
}

int randomPosition(int maxInt) {
	srand ((unsigned)time(0));
	 return (rand()%maxInt);
}

vector<int> sumX(vector<int> line) {
	for (int i = 0; i < 3; i++) {
		if (line[i] == line[i+1]) {
			line[i] = line[i] + line[i+1];
			line[i+1] = 0;
		}
	}

	return line;
}

vector<int> organizeLeft(vector<int> line) {
	vector<int> newLine = {0, 0, 0, 0};
	int position = 0;
	for (int i = 0; i < 4; i++) {
		if (line[i] != 0) {
			newLine[position] = line[i];
			position++;
		}
	}
	return newLine;
}

Plateau deplacementGauche(Plateau plateau) {
	vector<int> line;
	for (int i = 0; i < plateau.size(); i++) {
		line = plateau[i];
		line = organizeLeft(line);
		line = sumX(line);
		plateau[i] = organizeLeft(line);
	}
	return plateau;
}
