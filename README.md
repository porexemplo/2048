# Jeu 2048
Compiler et exécuter --windows :  `g++ main_game.cpp -o main_game modele.cpp && main_game.exe`

Compiler et exécuter -- linux : `g++ main_game.cpp -o main_game modele.cpp && ./main_game`

## Barême
La note 12/20 pourra être obtenue si:
- [x] les fichiers de votre projet compilent.
- [x] le jeu est fonctionnel.
- [x] le jeu respecte les règles du 2048.
- [ ] le score est mis è jour à chaque mouvement.
- [x] l’implantation respecte la structure imposée.
- [ ] toutes les fonctions sont spécifiées, documentées et testées.
- [x] lors de l’affichage, les colonnes sont bien alignées, quelles que soient les valeurs de chaque tuile.
- [ ] le rapport est bien rédigé (orthographe...) et comprend : Une présentation du jeu && Une **documentation** de votre application.
- [ ] la soutenance est soignée et inclut une brève démonstration de votre jeu.
 ### Niveau I
- [ ] rajouter un peu de couleur au console (1p)
- [ ] jouer en utilisant directement les flèches (haut, bas, gauche et droite) du clavier, sans avoir à appuyer sur entrée à chaque fois (2p)
- [x] l'affichage d'un plateau se fait à la place du plateau précédent -- refresh screen (2p)
- [ ] Calculer le score du jeu non pas avec une variable globale mais avec une structure de données qui associe un plateau `Plateau` à un score -- ncurses lib see subject (2p)
### Niveau II
- [ ] créer un `makefile` **simple** pour la compilation (2p)
- [ ] utiliser un "version control system" comme `git` (1p)
## Rappels GIT :
1. `git pull` -> mise à jour des fichiers locaux.
2. modifier les fichiers.
3. `git commit -a -m "un message des modifications"`
4. `git push` -> téleverser les fichiers vers Github.

----

## Algorithme

![image](https://user-images.githubusercontent.com/62790552/141335661-cbe08238-7b3c-4908-9e67-6bf23a776b08.png)
source: https://www.baeldung.com/
