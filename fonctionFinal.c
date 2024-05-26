#include "projetfishFinal.h"

// creation du plateau avec des valeurs aléatoires entre 0 et 3 pour le nombre de poisson
int ** init_plateau(int taille){


   int** plateau = malloc(taille * sizeof(int*));
   if (plateau == NULL) {
       exit(1);
   }


   for (int i = 0; i < taille; ++i) {
       plateau[i] = malloc(taille * sizeof(int));
       if (plateau[i] == NULL) {
           for (int j = 0; j < i; ++j) {
               free(plateau[j]);
           }
           free(plateau);
           exit(2);
       }
   }


   for(int i = 0 ; i<taille ; i++){
       for(int j =0 ; j<taille;j++){
           plateau[i][j]=rand()%4;
       }
   }


   return plateau;
}

// le plateau on l'affiche en ligne en commencant pas les chapeaux du haut
void printChapeau(int taille, int position) {
    int s = 0;

    if(position%2 ==1){printf("\\  "); } // condition pour savoir quand est ce qu'on commence par un chapeau droit
    while(s<taille){
        printf(" / \\  ");
        s++;
    }
     if(position%2 ==0){printf(" / "); }
    printf("\n");
    s = 0;if(position%2 ==1){printf(" \\ "); }
    while(s<taille){
         printf("/   \\ ");
        s++;
    }
     if(position%2 ==0){printf("/ "); }
 }

void printBarre(int **plateau, int position,int taille) {

    int j=0, s=0;
    if(position%2 ==1){printf("  |");}
    for (int j = 0; j < taille; j++) {
            int valeur = plateau[position][j];

            char poisson ;
            switch(valeur){
                case -1 : printf("| X | ");
                    break;
                case 1 :  printf("| * | ");
                    break;
                case 2 :  printf("|* *| ");
                    break;
                case 3 :  printf("|***| ");
                    break;
                case 4 :  printf("| 8 | ");
                    break;
                default : printf("|   | ");
            }
    }
    if(position%2 ==0){printf("|  ");}
    printf("\n");
    if(position%2 ==1){printf("  |");}
    while(s<taille){
       printf("|   | ");
       s++;
    }
     if(position%2 ==0){printf("|  ");}
}



//afficher le tableau grace au direct fonctions
void afficherPlateau(int **plateau,int taille) {
    int i =0;
    while(i<taille){
              printChapeau(taille,i);
         printf("\n");
        printBarre(plateau,i,taille);
        printf("\n");
        i++;
    }
    printChapeau(taille,1);
}

//procédure qui supprime les cases par lesquelles les pingouins sont passées



