#include "projetfishFinal.h"
Pingouin nouveauPingouin(int id){


   Pingouin nouveau_pingouin;


   nouveau_pingouin.id = id ;

    do{
   printf("Position horizontale : ");
   scanf("%d", &nouveau_pingouin.position.posX);

   printf("Position verticale : ");
   scanf("%d", &nouveau_pingouin.position.posY);
    }while(nouveau_pingouin.position.posX < 0 || nouveau_pingouin.position.posX >= 9 || nouveau_pingouin.position.posY < 0 || nouveau_pingouin.position.posY >= 9 );

    return nouveau_pingouin;
}


Player nouveauJoueur(int nbrPingouin){
   Player nouveau_joueur;
   printf("Nom joueur : ");
   scanf("%s",nouveau_joueur.nom);
   nouveau_joueur.nb_pingouin= nbrPingouin;
   nouveau_joueur.score= 0;
   return nouveau_joueur;
}




