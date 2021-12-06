/**
 * @file modele.cpp
 * @authors redwane, asma
 * @brief contains backend functions for the game
 * see @file modele.h for documentation
 * @copyright Copyright (c) 2021
 * 
 */

#include "modele.h"

// library to center text when working with setw()
#include "center_class.cpp"


using namespace std;


void timeInit() {
	srand ((unsigned)time(0));
}
// la fonction renvoie un plateau de 2 dimensions intialisé à 0
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
	plateau.score = 0;
	return plateau;
}
// premièrement on parours le plateau et on stocke les indices ({i,j}) des cases vides dans un tableau 2D 'positions' , et on renvoie un indice aléatoire de postions
// qui renvoie un tableau d'entier {i,j}
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
// renvoie un entier aléatorement soit 2 avec un pourcentage de 90% ou 4 avec un pourcentage de 10%
int tireDeuxOuQuatre() {
	vector<int> possib = {2, 4};
	bool TrueFalse = (rand() % 100) > 90;
	return possib[TrueFalse];
}
// grâcce à la fonction randomPosition qui renvoie les indices d'une case vide du plateau, on intialise cette case avec 2 ou 4 grâce à la fonction tireDeuxOuQuatre 
// Donc le rôle de la fonction addRadomTile et intialiser une case vide du plateau avec 2 ou 4 aléatoirement
Plateau addRandomTile(Plateau plateau) {
	vector<int> randPos = randomPosition(plateau);
	int i = randPos[0],
		j = randPos[1];
	plateau[i][j] = tireDeuxOuQuatre();
	return plateau;
}

// le but de  la fonction toLine convertit une ligne du plateau qui est un vector>int en line pour l'utiliser lors de l'appel des fonction sum ou organize
// qui prennet Line comme parametre
Line toLine(vector<int> convertVector) {
	Line returnLine (convertVector.size());
	for (int i = 0; i < convertVector.size(); i++) {
		returnLine[i] = convertVector[i];
	}
	return returnLine;
}

// note: default parameters should only be assigned in the function declaration, i.e. in modele.h
// la fonction sumX prend Line comme parametre , line doit déja être organisé grâce aux fonctions organize
// sumX verifie si 2 cases de line sont identitiques pour stocker la somme dans une case et 0 dans l'autre
// si le déplacement est gauche , le parcours de la droite sinon de la gauche si le déplacement est vers la droite
Line sumX(Line line, int dir/*=GAUCHE*/) {
	if (dir == GAUCHE) {
		for (int i = 0; i < 3; i++) {
			if (line[i] == line[i+1]) {
				line[i] = line[i] + line[i+1];
				line.score += line[i];
				line[i+1] = 0;
			}
		}
	}
	else if (dir == DROITE) {
		for (int i = 3; i > 0; i--) {
			if (line[i] == line[i-1]) {
				line[i] = line[i] + line[i-1];
				line.score += line[i];
				line[i-1] = 0;
			}
		}
	}
	return line;
}
// la fonction sumY prend Column comme parametre , column doit déja être organisé grâce aux fonctions organize
// sumY verifie si 2 cases de column sont identitiques pour stocker la somme dans une case et 0 dans l'autre
// si le déplacement est bas , le parcours du haut sinon de haut si le déplacement est vers le bas
Column sumY(Column column, int dir/*=HAUT*/){
	if (dir == HAUT) {
		for (int i = 0; i < 3; i++) {
			if (column[i][0] == column[i+1][0]) {
				column[i][0] = column[i][0] + column[i+1][0];
				column.score += column[i][0];
				column[i+1][0] = 0;
			}
		}
	}
	else if (dir == BAS) {
		for (int i = 3; i > 0; i--) {
			if (column[i][0] == column[i-1][0]) {
				column[i][0] = column[i][0] + column[i-1][0];
				column.score += column[i][0];
				column[i-1][0] = 0;
			}
		}
	}
	return column;
}
// la fonction organizeLeft prend une line comme argument , parours line de la droite , et renvoie newline en stockant que les les cases non vides dans newline
// le but est d'organiser les valeurs non nuls de line vers la gache
Line organizeLeft(Line line) {
	Line newLine = {0, 0, 0, 0};
	int position = 0;
	for (int i = 0; i < 4; i++) {
		if (line[i] != 0) {
			newLine[position] = line[i];
			position++;
		}
	}
	return newLine;
}
// la fonction organieRight prend une line comme argument , parours line de la gauche , et renvoie newline en stockant que les les cases non vides dans newline
// le but est d'organiser les valeurs non nuls de line vers la droite
Line organizeRight(Line line) {
	Line newLine = {0, 0, 0, 0};
	int position = 3;
	for (int i = 3; i >= 0 ; i--){
		if (line[i] != 0 ){
			newLine[position] = line[i];
			position--;
		}
	}
	return newLine;
}
// la fonction organizeUp prend column en argument , parours column du haut , et renvoie newcolumn en stockant que les les cases non vides dans newcolumn
// le but est d'organiser les valeurs non nuls de column vers la haut
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
// la fonction organieRight prend column en argument , parours column de la gauche , et renvoie newcolumn en stockant que les les cases non vides dans newcolumn
// le but est d'organiser les valeurs non nuls de column vers le bas
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
// la fonction du déplacement prend un plateau en argument
// convertit chaque ligne du platau qui est un vectort<int> en Type Line grâce à la fonction toLine
//chaque Line est organisé , sommé et organisé encore une fois selon le déplacement efféctué
// après chauqe mouvement, la somme effectué est stocké temporairement dans  score qui est un attribut de la classe Line ou Column pour assurer sa mise à jour après chauque mouvement

Plateau deplacementGauche(Plateau plateau) {
	Line line;
	for (int i = 0; i < plateau.size(); i++) {
		line = toLine(plateau[i]);
		line = organizeLeft(line);
		line.score = plateau.score;
		line = sumX(line, GAUCHE);
		plateau.score = line.score;
		plateau[i] = organizeLeft(line);
	}
	return plateau;
}

Plateau deplacementDroite(Plateau plateau) {
	Line line;
	for (int i = 0; i < plateau.size(); i++) {
		line = toLine(plateau[i]);
		line = organizeRight(line);
		line.score = plateau.score;
		line = sumX(line, DROITE);
		plateau.score = line.score;
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
		column.score = plateau.score;
		column = sumY(column, HAUT);
		plateau.score = column.score;
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
		column.score = plateau.score;
		column = sumY(column, BAS);
		plateau.score = column.score;
		column = organizeDown(column);

		for (int j = 0; j < plateau.size(); j++) {
			plateau[j][i] = column[j][0];
		}
	}
	return plateau;
}
 // fonction de déplacement qui à chaque direction de déplacement choisi, elle fait l'appel à la bonne fonction de déplacement qui renvoie le nouveau plateau 
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
// fonction qui renvoie un entier , le  nombre de chiffres dans un nombre
// but de la fonction
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
	flux << endl << "Score : " << g.score << endl << endl;
	for (int i = 0; i < g.size(); i++) {
		flux << starsDrawer();
		for (int j = 0; j < g[i].size(); j++) {
			int printValue = g[i][j];
			flux << "*" << get_color_of(printValue)
				 << setw(displayWidth);
			if (printValue) {
				flux << centered(to_string(printValue))
				     << "\033[0m";
			} else {
				flux << centered(" ");
			}
		}
		flux << "*";
		flux << endl;
	}
	flux << starsDrawer();
	return flux.str();
}
// le jeu se terminé quand le plateau renvoyé après chaque déplacement reste le même inchangé ; autrement dit aucun déplacement n'est possible
bool estTermine(Plateau plateau){
	vector<int> dir = {2, 4, 7, 8};
	for( int i : dir){
		if ( plateau != deplacement(plateau, i)){
			return false;
		}
	}
	return true;
}
// le joueur gagne si il parvient à arriver jusqu'à 2048, cependant le joueur va continuer à jouer jusqu'à ce que le jeu se termine 
bool estGagnant(Plateau plateau){
	for(int i = 0; i < plateau.size(); i++){
		for (int j = 0; j < plateau[i].size(); j++){
			if (plateau[i][j] == 2048){
				return true;
			}
		}
	}
	return false;
}
