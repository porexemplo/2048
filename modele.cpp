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

int randomPosition(int maxInt) {
	return (rand()%maxInt);
}

int tireDeuxOuQuatre() {
	vector<int> possib = {2, 4};
	bool TrueFalse = (rand() % 100) > 90;
	return possib[TrueFalse];
}

Plateau addRandomTile (Plateau plateau) { // @redwane
	if (plateau == plateauVide()) {
		int X = randomPosition(4),
			Y = randomPosition(4);
		plateau[X][Y] = tireDeuxOuQuatre();	
	}
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
Plateau deplacementDroite(Plateau plateau){
	vector<int> line;
	for (int i = 0; i < plateau.size(); i++) {
		line = plateau[i];
		line = organizeRight(line);
		line =sumX(line);
		plateau[i] = organizeRight(line);
	}
	return plateau;
	
Plateau sumY(Plateau plateauy){
	for (int i = 0; i<4; i++){
		for(int j =0; j<4; i++){
			if (plateauy[i][j] == plateauy[i][j+1]){
				plateauy[i][j]=plateauy[i][j]+plateauy[i][j+1];
				plateauy[i][j+1] = 0;
			}
		}
	
}
	return plateauy;
}


vector<int> organizeRight(vector<int> line) {
	vector<int>newLine ={0, 0, 0, 0};
	int position = 3;
	for (int i = 0; i<4 ; i++){
		if (line[i] != 0 ){
			newLine[position] = line[i];
			position = position-1;
		}
	}
	return newLine;
}
/*Plateau organizeUp(Plateau plateauy) {
	Plateau newPlateauy;
	for (int i =0; i<4:i++){
		for (int j =0; j<4;j++){
			newPlateauy[i][j]= 0;
		}
	}
	int ligne =0;
	int colonne = 0;
	for (int i =0; i<4:i++){
		for (int j =0; j<4;j++){
			if (plateauy[i][j] !=0){
				newPlateauy[ligne][colonne]= plateau[i][j];
				
				colonne++;
				if 
				*/


