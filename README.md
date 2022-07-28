# Jeu 2048
Projet INFO111 - Replica du jeu "2048" en C++ (SFML)

## Screenshot du jeu
![image](https://user-images.githubusercontent.com/62790552/181628573-7e6970d1-4b60-49ef-9525-f23a5183c663.png)


## Compilation & exécution
Compiler et exécuter --windows :  `g++ main_game.cpp -o main_game modele.cpp color.cpp && main_game.exe`

Compiler et exécuter -- linux : `g++ main_game.cpp -o main_game modele.cpp color.cpp && ./main_game`

Compiler (en utilisant le Makefile) : `make` puis : `main_game.exe` (windows) `./main_game` (linux)

## Barême (12 + 10 bonus)
La note 12/20 pourra être obtenue si:
- [x] les fichiers de votre projet compilent.
- [x] le jeu est fonctionnel.
- [x] le jeu respecte les règles du 2048.
- [x] le score est mis è jour à chaque mouvement.
- [x] l’implantation respecte la structure imposée.
- [x] toutes les fonctions sont spécifiées, documentées et testées.
- [x] lors de l’affichage, les colonnes sont bien alignées, quelles que soient les valeurs de chaque tuile.
- [x] le rapport est bien rédigé (orthographe...) et comprend : Une présentation du jeu && Une **documentation** de votre application.
- [x] la soutenance est soignée et inclut une brève démonstration de votre jeu.
 ### Niveau I
- [x] rajouter un peu de couleur au console (1p)
- [x] jouer en utilisant directement les flèches (haut, bas, gauche et droite) du clavier, sans avoir à appuyer sur entrée à chaque fois (2p)
- [x] l'affichage d'un plateau se fait à la place du plateau précédent -- refresh screen (2p)
- [x] Calculer le score du jeu non pas avec une variable globale mais avec une structure de données qui associe un plateau `Plateau` à un score -- ncurses lib see subject (2p)
### Niveau II
- [x] créer un `makefile` **simple** pour la compilation (2p) // [Makefiles](https://stackoverflow.com/questions/2481269/how-to-make-a-simple-c-makefile) sur Stackoverflow
- [x] utiliser un "version control system" comme `git` (1p)
### Niveau III
- [ ] Implanter une AI / joueur automatique
- [x] Implanter des variantes du jeu / créer la vôtre
- [x] Implanter une version de 2048 avec une interface graphique (2p)
- [ ] Une application android / iOS (2p)
## Rappels GIT :
1. `git pull` -> mise à jour des fichiers locaux.
2. modifier les fichiers.
3. `git commit -a -m "un message des modifications"`
4. `git push` -> téleverser les fichiers vers Github.
5. `git stash` -> annuler les modifications.

----

## Algorithme

![image](https://user-images.githubusercontent.com/62790552/141335661-cbe08238-7b3c-4908-9e67-6bf23a776b08.png)
source: https://www.baeldung.com/

Usefull resources :
Arrow keys : https://stackoverflow.com/questions/24708700/c-detect-when-user-presses-arrow-key
