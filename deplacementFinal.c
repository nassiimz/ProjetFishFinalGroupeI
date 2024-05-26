#include "projetfishFinal.h"
void viderCasePlateau(Position tab_position_a_supprimer[10] , int** plateau, int nbrDeplacement){
	for(int i=0;i<nbrDeplacement;i++){
		int posX = tab_position_a_supprimer[i].posX;
		int posY = tab_position_a_supprimer[i].posY;
		plateau[posX][posY] = 0;
	}
}


int valeurValide(int valeur){
	 if( valeur != -1 && valeur != 4){
	     return 1;
	 }
     return 0;
}

int verifierValeurCasePlateau(int **plateau, int taille,int newPosX,int newPosY){

    if(newPosY >= 0 && newPosX  >= 0 && newPosY < taille && newPosX <taille ){
	    int valeur = plateau[newPosX][newPosY] ;
	    if( valeurValide(valeur) == 1 ){
	         return 1;
	    }
	}

    return 0;
}



Position recupererNewPosition(Position oldPosition,int direction,int taille){
    int newPosX = oldPosition.posX;
    int newPosY = oldPosition.posY;
    switch(direction){
            case 1:{newPosY = newPosY+1;} break ;
            case 2:{newPosY = newPosY-1;} break ;
            case 3:{
                        if(newPosX % 2 != 0){
			                newPosY = newPosY+1;
		                }
		                newPosX = newPosX-1;
                    } break ;
            case 4:{
                        if(newPosX % 2 == 0){
            		    	newPosY = newPosY-1;
            	    	}
            	    	newPosX = newPosX-1;
                    } break ;
            case 5:{
                        if(newPosX % 2 != 0){
			                newPosY = newPosY+1;
		                }
		                newPosX = newPosX+1;
                    } break ;
            case 6:{
                         if(newPosX % 2 == 0){
			                   newPosY = newPosY-1;
                            }
	            	    newPosX = newPosX+1;
                    } break ;
        }

        if (newPosX >= taille || newPosX < 0 || newPosY >= taille || newPosY < 0 ){
             newPosX = taille ;
             newPosY = taille ;
        }

        Position newPosition ;
        newPosition.posX = newPosX;
        newPosition.posY = newPosY;

        return newPosition;
}


int deplacementPingouin(int positionPingouinChoisi,int taille,int **plateau, int nbrDeplacement,Player* player,int direction){
    Pingouin pingouin = player->tab_pingouin[positionPingouinChoisi];
    Position newPosition ;
    newPosition.posX = pingouin.position.posX;
    newPosition.posY = pingouin.position.posY;
    int newScore = player->score;
    Position tab_position_a_supprimer[20];

    for(int i=0;i<nbrDeplacement;i++){

         /// 1- Droite   2- Gauche   3- Haut Droite   4- Haut Gauche   5- Bas Droite   6- Bas Gauche

         newPosition = recupererNewPosition(newPosition,direction,taille);

        if(verifierValeurCasePlateau(plateau,  taille, newPosition.posX, newPosition.posY) == 0){
	         return 0;
	    }


	    int valeur = plateau[newPosition.posX][newPosition.posY];
	    newScore = newScore + valeur ;
    	Position position_supprimer ;
    	position_supprimer.posX = newPosition.posX;
    	position_supprimer.posY = newPosition.posY;
    	tab_position_a_supprimer[i] = position_supprimer;
    }

    viderCasePlateau(tab_position_a_supprimer , plateau, nbrDeplacement);

    player->score = newScore ;

    plateau[pingouin.position.posX][pingouin.position.posY] = -1;
	plateau[newPosition.posX][newPosition.posY] = 4;
	player->tab_pingouin[positionPingouinChoisi].position.posX = newPosition.posX;
	player->tab_pingouin[positionPingouinChoisi].position.posY = newPosition.posY;

	return 1;
}




int verifierPossibiliteDeplacement(Pingouin pingouin, int **plateau, int taille){
	Position newPosition ;
    for(int i =1; i < 7; i++){
	    newPosition.posX = pingouin.position.posX;
        newPosition.posY = pingouin.position.posY;
        newPosition =  recupererNewPosition(newPosition,i,taille);
       	if(verifierValeurCasePlateau(plateau,  taille,  newPosition.posX, newPosition.posY) == 1){
    	    return 1;
    	 }
    }

 return 0;
}

void deplacement(int taille,int **plateau,Player* player){

      int positionPingouinChoisi;
      int direction;
      int nbrDeplacement;


            do{

               // do{
                printf("Choisi la position du Pingouin a deplacer: ");
                scanf("%d",&positionPingouinChoisi);
                printf("\n");
               // }while(positionPingouinChoisi >= player->nb_pingouin || positionPingouinChoisi <-1);


               do{
                   printf("\n Choisi le numero de la direction \n 1- Droite \n 2- Gauche \n 3- Haut Droite \n 4- Haut Gauche \n 5- Bas Droite \n 6- Bas Gauche \n");
                   printf("Votre choix : ");
                   scanf("%d",&direction);
                }while(direction<1 || direction>6);


                do {
                        printf(" \n Choisi le nombre de deplacement : ");
                        scanf("%d",&nbrDeplacement);
                } while(nbrDeplacement<-1 || nbrDeplacement>taille-1 );



        }while(deplacementPingouin(positionPingouinChoisi, taille,plateau,nbrDeplacement,player,direction) == 0);


       printf("\n********************************************************************* \n");
       printf(" \n Nouveau score de : %s est : % d \n",player->nom , player->score);
       printf("\n********************************************************************* \n");
}



int verificationPingouinParJoueur(int taille,int **plateau,Player* player){


                printf("******************************** \n ");
                printf("Pingouin disponible : \n ");
                int nombrePingouinDeplacable = 0;
                for(int j = 0; j<player->nb_pingouin; j++){

                    Pingouin pingouin = player->tab_pingouin[j] ;

                   if(verifierPossibiliteDeplacement(pingouin, plateau,taille)  == 0){

                       continue;
                    }
                    nombrePingouinDeplacable ++;
                      printf(" Pingouin  %d : ", j );
                      printf(" x =  %d ", pingouin.position.posX );
                      printf(" y =  %d  ",pingouin.position.posY );
                      printf("\n");
                }

                if(nombrePingouinDeplacable == 0){
                    return 0;
                }

                printf("******************************** \n ");


                deplacement(taille,plateau,player);

                return 1;



}

int calculeNombrePoissonDisponible(int taille,int **plateau){
    int i = 0;
    int NombrePoissonDisponible = 0;
    for(int i= 0;i<taille;i++){
        for(int j= 0;j<taille;j++){
            int valeur = plateau[i][j];
            if(valeurValide(valeur) == 1){
                NombrePoissonDisponible = NombrePoissonDisponible + valeur;
            }
        }

    }
    return NombrePoissonDisponible;
}

int verifierPingouinExistant(int x,int y,Position tab_position_utiliser[9]){
    for(int i=0;i<9;i++){
        if(tab_position_utiliser[i].posX == x && tab_position_utiliser[i].posY == y ){
            return 1;
        }
    }
    return 0;
}

//procédure qui supprime les cases par lesquelles les pingouins sont passées
void viderTablepositionUtiliser(Position tab_position_utiliser[9]){
    for(int i=0;i<9;i++){
        Position positionVide ;
        positionVide.posX = -1;
        positionVide.posY = -1;
        tab_position_utiliser[i] = positionVide;
    }
}


