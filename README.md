Description
Ce projet est un jeu de plateau où des joueurs contrôlent des pingouins pour
accumuler des points en se déplaçant sur un plateau hexagonal. Chaque joueur
place ses pingouins au début du jeu et les déplace tour à tour pour accumuler des
points en ramassant des poissons. Le jeu se termine lorsque plus aucun joueur ne
peut déplacer ses pingouins.
Compilation
Pour compiler le programme, assurez-vous d'avoir un compilateur C installé (comme
gcc).
Exécution
Une fois le programme compilé, exécutez-le avec la commande suivante: make.
Instructions de jeu
1. Initialisation des Joueurs:
	● Le jeu commence en demandant le nombre de joueurs (entre 2 et 6).
	● Ensuite, chaque joueur doit entrer son nom et positionner ses
pingouins sur le plateau.
2. Déroulement du jeu:
● Les joueurs se relaient pour déplacer leurs pingouins.
● À chaque tour, le joueur choisit un pingouin à déplacer, une direction et
le nombre de cases à parcourir.
● Les déplacements sont soumis à des règles de validité (les pingouins
ne peuvent pas se déplacer sur des cases vides ou en dehors du
plateau).
3. Fin de la partie:
● Le jeu se termine lorsqu'aucun joueur ne peut plus déplacer ses
pingouins ou qu'il ne reste plus de poissons disponibles.
● Le joueur avec le score le plus élevé gagne.
Structure du code
Types de Données
● Position: Structure représentant les coordonnées (x, y ( y représente les
lignes verticales et x horizontale)) sur le plateau.
● Pingouin: Structure représentant un pingouin avec un identifiant et une
position.
● Player: Structure représentant un joueur avec un nom, un nombre de
pingouins, un score, et un tableau de pingouins.
Fonctions Principales
● nouveauPingouin(int id): Initialise un nouveau pingouin en demandant sa
position à l'utilisateur.
● nouveauJoueur(int nbrPingouin): Initialise un nouveau joueur en
demandant son nom à l'utilisateur.
● init_plateau(int taille): Initialise le plateau de jeu avec des valeurs
aléatoires de poissons.
● afficherPlateau(int **plateau, int taille): Affiche le plateau de jeu.
● deplacementPingouin(...): Gère le déplacement des pingouins sur le
plateau.
● verificationPingouinParJoueur(...): Vérifie si un joueur peut déplacer un
de ses pingouins.
● calculeNombrePoissonDisponible(int taille, int **plateau): Calcule
le nombre de poissons disponibles sur le plateau.
● main(): Fonction principale qui est chargé le déroulement du jeu.
