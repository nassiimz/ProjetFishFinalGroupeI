
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include<stdbool.h>

typedef struct Position{
   int posX;
   int posY;
}Position;




typedef struct Pingouin{
   int id;
   Position position;
}Pingouin;


typedef struct Player{
   int num_joueur;
   int  nb_pingouin;
   int score;
   char nom[50];
   Pingouin tab_pingouin[4];


} Player;


int valeurValide(int valeur);

int verifierValeurCasePlateau(int **plateau, int taille,int newPosX,int newPosY);

Position recupererNewPosition(Position oldPosition,int direction,int taille);

int deplacementPingouin(int positionPingouinChoisi,int taille,int **plateau, int nbrDeplacement,Player* player,int direction);

int verifierPossibiliteDeplacement(Pingouin pingouin, int **plateau, int taille);

void deplacement(int taille,int **plateau,Player* player);

int verificationPingouinParJoueur(int taille,int **plateau,Player* player);

int calculeNombrePoissonDisponible(int taille,int **plateau);

int verifierPingouinExistant(int x,int y,Position tab_position_utiliser[9]);

void viderTablepositionUtiliser(Position tab_position_utiliser[9]);

int ** init_plateau(int taille);

void printChapeau(int taille, int position);

void printBarre(int **plateau, int position,int taille);

void afficherPlateau(int **plateau,int taille);

Pingouin nouveauPingouin(int id);

Player nouveauJoueur(int nbrPingouin);


