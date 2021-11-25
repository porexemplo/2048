#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "modele.h"
#include "center_class.cpp"
#include <SFML/Graphics.hpp>

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
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
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
	temp = plateau[4][0];
	for (int i = 0; i < 4; i++) {
		line = plateau[i];
		line = organizeLeft(line);
		line = sumX(line, GAUCHE);
		plateau[i] = organizeLeft(line);
	}
	plateau[4][0] = temp;
	return plateau;
}

Plateau deplacementDroite(Plateau plateau) {
	vector<int> line;
	for (int i = 0; i < 4; i++) {
		line = plateau[i];
		line = organizeRight(line);
		line = sumX(line, DROITE);
		plateau[i] = organizeRight(line);
	}
	return plateau;
}

Plateau deplacementHaut(Plateau plateau) {
	Column column (4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			column[j] = vector<int> (1);
			column[j][0] = plateau[j][i];
		}
		column = organizeUp(column);
		column = sumY(column, HAUT);
		column = organizeUp(column);

		for (int j = 0; j < 4; j++) {
			plateau[j][i] = column[j][0];
		}
	}
	return plateau;
}

Plateau deplacementBas(Plateau plateau) {
	Column column (4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			column[j] = vector<int> (1);
			column[j][0] = plateau[j][i];
		}
		column = organizeDown(column);
		column = sumY(column, BAS);
		column = organizeDown(column);

		for (int j = 0; j < 4; j++) {
			plateau[j][i] = column[j][0];
		}
	}
	return plateau;
}

Plateau deplacement(Plateau plateau, int direction) {
	Plateau oldPlateau = plateau;
	if (direction == GAUCHE) {
		plateau = deplacementGauche(plateau);
	}
	else if (direction == DROITE) {
		plateau = deplacementDroite(plateau);
	}
	else if (direction == HAUT) {
		plateau = deplacementHaut(plateau);
	}
	else if (direction == BAS) {
		plateau = deplacementBas(plateau);
	} else {
		return plateau;
	}

	if (plateau != oldPlateau) {
		plateau = addRandomTile(plateau);
	}
	return plateau;
}

int lenInt(int number) {
	int len = 1;
	for (int i = 10; number - i >= 0; i = i*10) {
        len++;
    }
	return len;
}

string starsDrawer() {
	ostringstream flux;
	for (int i = 0; i < ((displayWidth + 1)*4 +1); i++)
		flux << "*";
	flux << endl;
	return flux.str();
}

string dessine(Plateau g) {
	ostringstream flux;
	flux << endl;
	for (int i = 0; i < 4; i++) {
		flux << starsDrawer();
		for (int j = 0; j < 4; j++) {
			int printValue = g[i][j];
			flux << "*" << setw(displayWidth) << centered(to_string(printValue));
		}
		flux << "*" << endl;
	}
	flux << starsDrawer();
	return flux.str();
}

bool estTermine(Plateau plateau){
	vector<int> dir = { 2,4,7,8};
	for( int i : dir){
		if ( plateau != deplacement( plateau, i)){
			return false;
		}
	}
	return true;
}

bool estGagnant(Plateau plateau){
	for(int i=0; i<4; i++){
		for (int j =0; j<4; j++){
			if (plateau[i][j] == 2048){
				return true;
			}
		}
	}
	return false;
}

/*
int score(Plateau plateau){
	int score = 0;
	while (not est terminée){
		for (int i =0; i<4; i++)
				if (plateau[i]= sumX(plateau [i], 7) 
			
	*/	
	

