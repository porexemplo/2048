/**
 * @file modele.h
 * @authors redwane, asma
 * @brief contains function declarations and necessary libraries for the file
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// ISSUE : FIXED : multiple definitions of the same class -> pragma once
#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

// conio.h library exists for windows only
#if defined _WIN32 || defined _WIN64
    #include <conio.h>
    #define inSystem 1
#else
    #define inSystem 0
#endif
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cassert>
#include "color.h"

using namespace std;

// directions for conio.h arrow detection
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

const int GAUCHE = 7,
          DROITE = 4,
          HAUT = 8,
          BAS = 2;

const int displayWidth = 7; // controls console display width


// Plateau class inherits from vector<vector<int>> with score attribute
class Plateau: public vector<vector<int>> {
public:
    // ISSUE : FIXED : constructors are not inherited by default
    using vector::vector;
    int score;
};

class Column: public vector<vector<int>> {
public:
    using vector::vector;
    int score;
};

class Line: public vector<int> {
public:
    using vector::vector;
    int score;
};


/**
 * @return un plateau vide
*/
Plateau plateauVide();

/**
 * @brief initialise un nouveau jeu
 *
 * @return un plateau initialisé i.e. avec deux valeurs réparties aléatoirement
*/
Plateau plateauInitial();


/**
 * @brief  fonction qui renvoie les indices d'une case vide du plateau
 * 
 * @param un plateau  
 * @return un vector<int> aléatoirement qui indique les indices du case du plateau vide i et j 
 */
vector<int> randomPosition(Plateau plateau);

/**
 * @brief génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 * 
 * @return un entier dans l'ensemble {2, 4}
 */
int tireDeuxOuQuatre();

/**
 * @brief réalise un déplacement gauche suivant les règles du jeu; renvoie un nouveau plateau
 * 
 * @param plateau 
 * @return ** Plateau après le déplacement
 */
Plateau deplacementGauche(Plateau plateau);

/**
 * @brief déplacement vers la droite suivant les règles du jeu; renvoie un nouveau plateau
 * 
 * @param plateau 
 * @return ** Plateau après le déplacement
 */
Plateau deplacementDroite(Plateau plateau); // @asma

/**
 * @brief déplacement vers le haut suivant les règles du jeu; renvoie un nouveau plateau
 * @param plateau 
 * @return ** Plateau après le déplacement
 */
Plateau deplacementHaut(Plateau plateau); // @asma

/**
 * @brief déplacement vers le bas suivant les règles du jeu; renvoie un nouveau plateau
 * 
 * @param plateau Plateau
 * @return ** Plateau après le déplacement
 */
Plateau deplacementBas(Plateau plateau); // @redwane

/**
 * @brief effectue un déplacement en éxecutant l'une des fonctions de déplacement
 * 
 * @param plateau Plateau
 * @param direction un entier parmi {7, 4, 8, 2} - voir variables const.
 * @return Plateau après déplacement
 */
Plateau deplacement(Plateau plateau, int direction); // @all


/**
 * @brief affiche des étoiles
 * @return string 
 */
string starsDrawer();

/**
 * @brief affiche le plateau g au console
 * 
 * @param g un lateau
 * @return string 
 */
string dessine(Plateau g); // @all

/**
 * @brief vérifie si la partie est terminée
 * la partie est terminée s'il y a pas de mouvements possible
 * i.e. deplacement(plateau) == plateau qlq soit la direction
 * 
 * @param plateau 
 * @return true s'il y a au moins un mouvement possible
 * @return false s'il y a aucun mouvement possible
 */
bool estTermine(Plateau plateau);


/**
 * @brief vérifie si le joueur a gagné la partie
 * 
 * @param plateau 
 * @return true si maxCells >= 2048
 * @return false sinon
 */
bool estGagnant(Plateau plateau);

/**
 * @brief fait la somme de 2 cases identiques sur une même ligne 
 * 
 * @param Line line, qui prend une ligne du plateau comme attribut
 * @param int, entier qui définie la direction du mouvement 
 * @return line telle que la somme des 2 cases identiques dans une case et 0 dans 2 ème case
 */
Line sumX(Line line, int dir=GAUCHE);

/**
 * @brief fait la somme de 2 cases identiques sur une même colonnes 
 * 
 * @param column Column 
 * @param dir int qui définie la direction du mouvement 
 * @return colonne telle que la somme des 2 cases identiques dans une case et 0 dans 2 ème case sur une meme colonne 
 */

Column sumY(Column column, int dir=HAUT);
/**
 * @brief organise les lignes du tableau vers la gauche 
 * 
 * @param line vector<int>, ligne du tableau
 * @param newline vector<int>, la nouvelle ligne qui sera renvoyée 
 * @return une nouvelle ligne organisée de sorte que tous les nombres différents de 0 sont déplacés vers la gauche
 */
vector<int> organizeLeft(vector<int> line);

/**
 * @brief organise les lignes du tableau vers le haut
 * 
 * @param Column Column
 * @param Column newolumn, column de 4 lignes et une colonne  qui sera renvoyée 
 * @return newcolumn organisée de sorte que tous les nombres différents de 0 sont déplacés vers le haut
 */
Column organizeUp(Column column);

/**
 * @brief organise les lignes du tableau vers le bas
 * 
 * @param Column Column
 * @param Column newolumn, column de 4 lignes et une colonne  qui sera renvoyée 
 * @return newcolumn organisée de sorte que tous les nombres différents de 0 sont déplacés vers le bas
 */
Column organizeDown(Column column);

/**
 * @brief choisit une case aléatoire du tableau et renvoie soit 2 ou 4 dans la case
 * 
 * @param plateau 
 * @param int i qui est initialisé à une valeur aléatoire, représente les lignes du tableau 
 * @param int j qui est initialisé à une valeur aléatoire, représente les colonnes du tableau 
 * @return dans la case du tableau aléatoire, on renvoie soit 2 ou 4  avec la fonction tireDeuxOuQuatre 
 */
Plateau addRandomTile(Plateau plateau);

/**
 * @brief organise les lignes du tableau vers la droite
 * 
 * @param line vector<int>, ligne du tableau
 * @param newline vector<int>, la nouvelle ligne qui sera renvoyée 
 * @return une nouvelle ligne organisée de sorte que tous les nombres différents de 0 sont déplacés vers la droite
 */
vector<int> organizeRight(vector<int> line);

/**
 * @brief calcule le nombre des chiffres
 * @param number int
 * @return la longueur de number
 */
int lenInt(int number);

/**
 * @brief type conversion function from vector<int> to Line type
 * 
 * @param convertVector 
 * @return Line 
 */
Line toLine(vector<int> convertVector);

/**
 * @brief srands based on time, implemented in main_game.cpp
 * 
 */
void timeInit();
