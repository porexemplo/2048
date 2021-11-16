#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "modele.h"

using namespace std;

void timeInit() {
	srand ((unsigned)time(0));
}

Plateau plateauVide() {
	Plateau plaVide (4);
	for (int i = 0; i < 4; i++) {
		plaVide[i] = {0, 0, 0, 0};
	}
	return plaVide;
}

Plateau plateauInitial() {
	Plateau plateau = plateauVide();
	plateau = addRandomTile(plateau);
	plateau = addRandomTile(plateau);
	return plateau;
}

vector<int> randomPosition(Plateau plateau) {
	vector<vector<int>> positions;
	for (int i = 0; i < plateau.size(); i++) {
		for (int j = 0; j < plateau.size(); j++) {
			if (plateau[i][j] == 0) {
				positions.push_back({i, j});
			}
		}
	}
	for (auto line : positions) {
        for (int element : line) {
            cout << element << " ";
        }
        cout << endl;
	}
	return positions[(rand() % positions.size())];
}

int tireDeuxOuQuatre() {
	vector<int> possib = {2, 4};
	bool TrueFalse = (rand() % 100) > 90;
	return possib[TrueFalse];
}

Plateau addRandomTile (Plateau plateau) {
	int i = randomPosition(plateau)[0],
		j = randomPosition(plateau)[1];
	plateau[i][j] = tireDeuxOuQuatre();
	return plateau;
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

Column sumY(Column column){
	for (int i = 0; i < 3; i++) {
		if (column[i][0] == column[i+1][0]) {
			column[i][0] = column[i][0] + column[i+1][0];
			column[i+1][0] = 0;
		}
	}
	return column;
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

vector<int> organizeRight(vector<int> line) {
	vector<int> newLine = {0, 0, 0, 0};
	int position = 3;
	for (int i = 3; i >= 0 ; i--){
		if (line[i] != 0 ){
			newLine[position] = line[i];
			position--;
		}
	}
	return newLine;
}

Column organizeUp(Column column) {
	Column newColumn = {{0},
					    {0},
						{0},
						{0}};
	int position = 0;
	for (int i = 0; i < 4; i++) {
		if (column[i][0] != 0) {
			newColumn[position][0] = column[i][0];
			position++;
		}
	}
	return newColumn;
}

Column organizeDown(Column column) {
	Column newColumn = {{0},
					    {0},
						{0},
						{0}};
	int position = 3;
	for (int i = 3; i >= 0; i--) {
		if (column[i][0] != 0) {
			newColumn[position][0] = column[i][0];
			position--;
		}
	}
	return newColumn;
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

Plateau deplacementDroite(Plateau plateau) {
	vector<int> line;
	for (int i = 0; i < plateau.size(); i++) {
		line = plateau[i];
		line = organizeRight(line);
		line = sumX(line);
		plateau[i] = organizeRight(line);
	}
	return plateau;
}

Plateau deplacementHaut(Plateau plateau) {
	Column column (4);
	for (int i = 0; i < plateau.size(); i++) {
		for (int j = 0; j < plateau.size(); j++) {
			column[j] = vector<int> (1);
			column[j][0] = plateau[j][i];
		}
		column = organizeUp(column);
		column = sumY(column);
		column = organizeUp(column);

		for (int j = 0; j < plateau.size(); j++) {
			plateau[j][i] = column[j][0];
		}
	}
	return plateau;
}

Plateau deplacementBas(Plateau plateau) {
	Column column (4);
	for (int i = 0; i < plateau.size(); i++) {
		for (int j = 0; j < plateau.size(); j++) {
			column[j] = vector<int> (1);
			column[j][0] = plateau[j][i];
		}
		column = organizeDown(column);
		column = sumY(column);
		column = organizeDown(column);

		for (int j = 0; j < plateau.size(); j++) {
			plateau[j][i] = column[j][0];
		}
	}
	return plateau;
}

Plateau deplacement(Plateau plateau, int direction) {
	if (direction == GAUCHE) {
		plateau = deplacementGauche(plateau);
	}
	if (direction == DROITE) {
		plateau = deplacementDroite(plateau);
	}
	if (direction == HAUT) {
		plateau = deplacementHaut(plateau);
	}
	if (direction == BAS) {
		plateau = deplacementBas(plateau);
	}
	return plateau;
}
