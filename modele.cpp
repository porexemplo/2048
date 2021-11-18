#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "modele.h"
#include "center_class.cpp"

using namespace std;

// this is a comment

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
	return positions[(rand() % positions.size())];
}

int tireDeuxOuQuatre() {
	vector<int> possib = {2, 4};
	bool TrueFalse = (rand() % 100) > 90;
	return possib[TrueFalse];
}

Plateau addRandomTile(Plateau plateau) {
	vector<int> randPos = randomPosition(plateau);
	int i = randPos[0],
		j = randPos[1];
	plateau[i][j] = tireDeuxOuQuatre();
	return plateau;
}

// note: default parameters should only be assigned in the function declaration, i.e. in modele.h
vector<int> sumX(vector<int> line, int dir/*=GAUCHE*/) {
	if (dir == GAUCHE) {
		for (int i = 0; i < 3; i++) {
			if (line[i] == line[i+1]) {
				line[i] = line[i] + line[i+1];
				line[i+1] = 0;
			}
		}
	}
	else if (dir == DROITE) {
		for (int i = 3; i > 0; i--) {
			if (line[i] == line[i-1]) {
				line[i] = line[i] + line[i-1];
				line[i-1] = 0;
			}
		}
	}
	return line;
}

Column sumY(Column column, int dir/*=HAUT*/){
	if (dir == HAUT) {
		for (int i = 0; i < 3; i++) {
			if (column[i][0] == column[i+1][0]) {
				column[i][0] = column[i][0] + column[i+1][0];
				column[i+1][0] = 0;
			}
		}
	}
	else if (dir == BAS) {
		for (int i = 3; i > 0; i--) {
			if (column[i][0] == column[i-1][0]) {
				column[i][0] = column[i][0] + column[i-1][0];
				column[i-1][0] = 0;
			}
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
		line = sumX(line, GAUCHE);
		plateau[i] = organizeLeft(line);
	}
	return plateau;
}

Plateau deplacementDroite(Plateau plateau) {
	vector<int> line;
	for (int i = 0; i < plateau.size(); i++) {
		line = plateau[i];
		line = organizeRight(line);
		line = sumX(line, DROITE);
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
		column = sumY(column, HAUT);
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
		column = sumY(column, BAS);
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

	plateau = addRandomTile(plateau);
	return plateau;
}

int lenInt(int number) {
	int len = 1;
	for (int i = 10; number - i >= 0; i = i*10) {
        len++;
    }
	return len;
}

void starsDrawer() {
	for (int i = 0; i < ((8 + 1)*4); i++)
		cout << "*";
	cout << endl;
}

void dessine(Plateau g) {
	cout << endl;
	for (int i = 0; i < g.size(); i++) {
		starsDrawer();
		for (int j = 0; j < g[i].size(); j++) {
			int printValue = g[i][j];
			// cout << setw(8);
			cout << "*";
			cout << setw(8);
			cout << centered(to_string(printValue));
			// if (j == 3) cout << "*";
		}
	cout << endl << endl;
	}
	starsDrawer();
}
