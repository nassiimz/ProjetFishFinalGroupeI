#include "projetfishFinal.h"

int main() {
   int taille = 9;    // taille du plateau
   int** plateau = init_plateau(taille);
   Position tab_position_utiliser[9] ;
   Player tab_player[6];
   int nbr_max_pingouin;
   int id =0;
   int nombre_joueur = 0;

   viderTablepositionUtiliser(tab_position_utiliser);

   do{
       printf("Nombre de joueurs : ");
       scanf("%d",&nombre_joueur);
   }while(nombre_joueur<2 || nombre_joueur>6);;
    //switch pour determiner le nombre de pingouins par personnes par rapport au nombre de joueurs
    switch(nombre_joueur){
       case 2 : nbr_max_pingouin =4;
       break;
       case 3 : nbr_max_pingouin =3;
       break;
       case 4 : nbr_max_pingouin =2;
       break;
       default : nbr_max_pingouin=1;
    }

    //boucle pour demander a chaques utilisateurs de placer son ou ses pingouins
   for(int i = 0; i<nombre_joueur; i++){
        printf("Initialisation du joueur N° = %d \n",i+1);
          Player player;
          player = nouveauJoueur(nbr_max_pingouin);
           printf("\n");
           for(int j = 0; j < nbr_max_pingouin; j++){


              Pingouin p ;
              do{
               printf("Positionne ton pingouin N° = %d  \n",j+1);
                p =  nouveauPingouin(id);
              }while(verifierPingouinExistant(p.position.posX,p.position.posY,tab_position_utiliser) == 1); // appel de la fonction pour savoir si il y a deja un pingouin sur cette case


               plateau[p.position.posX][p.position.posY] = 4; //place le pingouin grace a la valeur 4
               player.tab_pingouin[j] = p; //place le pingouin dans la tab des pingouins du joueur
               tab_position_utiliser[id]=p.position; //met la position dans un tableau des position utilisé
               id++;
               printf("\n");
           }
           tab_player[i] = player;
        printf("-----------------------------------------------------------\n");
   }

    afficherPlateau(plateau,taille); // reaffiche le plateau avec les pingouins placés

     printf(" \n Debut de la partie \n");


   int nombreJoueurBloque = 0;

    do{
        for(int i = 0; i < nombre_joueur; i++){

                Player player = tab_player[i];

                printf("\n C'est le tour de : %s avec un score de : %d \n",player.nom,player.score); // affiche le score au fur et a mesure

                if(verificationPingouinParJoueur(taille,plateau,&tab_player[i]) == 1){

                     afficherPlateau(plateau,taille);

                }else{
                       nombreJoueurBloque ++;
                       printf("Aucun pingouin est deplaçable \n");
                }
        }
    }while(nombreJoueurBloque != nombre_joueur || calculeNombrePoissonDisponible(taille,plateau) > 0); //la partie dure jusqu'à ce que tous les joueurs soient bloqués ou que le nombre de poisson soit de 0 sur le plateau

     printf("Finde la partie \n");

     int maxScore  = tab_player[0].score;
     Player playerWinner = tab_player[0];

     printf("Scores finaux : \n");
     //boucle qui affiche le score de chaques joueurs
     for(int i = 0; i < nombre_joueur; i++){
         Player player = tab_player[i];
            //boucle pour définir le gagnant
         if(player.score > maxScore ){
             maxScore = player.score;
             playerWinner = player;
         }

         printf("Nom joueur : %s Score : %d \n",player.nom,player.score);
     }


      printf("Le grand gagnant est le : %s avec un score de : %d \n",playerWinner.nom,playerWinner.score);


    return 0;
}

