#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int GAUCHE = 7,
          DROITE = 4,
          HAUT = 8,
          BAS = 2;

typedef vector< vector<int> > Plateau;

/**
 * @returns un plateau vide
*/
Plateau plateauVide();

/**
 * @brief initialise un nouveau jeu
 *
 * @returns un plateau initialisé i.e. avec deux valeurs réparties aléatoirement
*/
Plateau plateauInitial();

/**
 * @brief renvoi un entier < maxInt aléatoirement
 * 
 * @param maxInt 
 * @return un entier compris entre 0 et maxInt
 */
int randomPosition(int maxInt);

/**
 * @brief tirer 2 ou 4 aléatoirement
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
 * 
 * @param plateau 
 * @return ** Plateau après le déplacement
 */
Plateau deplacementHaut(Plateau plateau); // @asma

/**
 * @brief déplacement vers le bas suivant les règles du jeu; renvoie un nouveau plateau
 * 
 * @param plateau 
 * @return ** Plateau après le déplacement
 */
Plateau deplacementBas(Plateau plateau); // @redwane

/**
 * @brief effectue un déplacement en éxecutant l'une des fonctions de déplacement
 * 
 * @param plateau
 * @param direction un entier parmi {7, 4, 8, 2} - voir variables const.
 * @return Plateau après déplacement
 */
Plateau deplacement(Plateau plateau, int direction); // @all

/**
 * @brief affiche le plateau g au console
 * 
 * @param g un plateau
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
 * @brief détermine le score de la partie
 * 
 * @param plateau 
 * @return int score de la partie.
 */
int score(Plateau plateau);

vector<int> sumX(vector<int> line);
/**
 * @brief organise les lignes du tableau vers la guache 
 * 
 * @param vector<int> line, ligne du tableau
 * @param vector<int> newline, la nouvelle ligne qui sera renvoyée 
 * @return une nouvelle ligne organisée de sorte que tous les nombres différents de 0 sont déplacés vers la gauche
 */
vector<int> organizeLeft(vector<int> line);

/**
 * @brief choisit une case aléatoire du tableau et renvoie soit 2 ou 4 dans la case
 * 
 * @param plateau 
 * @param int i qui est initialisé à une valeur aléatoire, représente les lignes du tableau 
 * @param int j qui est initialisé à une valeur aléatoire, représente les colonnes du tableau 
 * @return dans la case du tableau aléatoire, on renvoie soit 2 ou 4  avec la fonction tireDeuxOuQuatre 
 */
Plateau addRandomTile (Plateau plateau);

/**
 * @brief organise les lignes du tableau vers la droite
 * 
 * @param vector<int> line, ligne du tableau
 * @param vector<int> newline, la nouvelle ligne qui sera renvoyée 
 * @return une nouvelle ligne organisée de sorte que tous les nombres différents de 0 sont déplacés vers la droite
 */
vector<int> organizeRight(vector<int> line) ;

void timeInit();

vector<int> sumY(Plateau plateauy);


