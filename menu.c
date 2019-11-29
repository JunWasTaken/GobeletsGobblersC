#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int choiceSelector(int x){
    int choix;
    int returnValue=0;
    
    do{
        printf("Votre Choix : ");
        scanf("%d", &choix);
        if (choix >= 1 && choix <= x){
            returnValue = choix;
        }
        else
        {
            printf("Veuillez saisir une valeur valide\n");
        }
    }while(choix < 1 || choix > x);
    printf("test choice selector\n");
    return returnValue;
}

void affichagePlateau(board game){
    for (int i=0; i<DIMENSIONS; i++){
        for (int j=0; j<DIMENSIONS; j++){
            printf("%d ", get_place_holder(game, i, j));
        }
        printf("\n");
    }
}

void TourJeu(player x, board game){
    int choix = 0, column=0, row=0, res=4;
    unsigned int pieceSize=0; 
    printf("Que voulez-vous faire ?\n1-Placer un pion\n2-Déplacer un pion\n");
    choix = choiceSelector(2);
    if (choix==1){
        printf("Quelle taille de pièce voulez-vous jouer ? Petite, Moyenne ou Grande\n(Faire un choix entre 1 et 3) -> ");
        pieceSize=choiceSelector(3);
        /*while(!get_nb_piece_in_house(game, x, pieceSize)){
            printf("Veuillez faire un choix valide\n");
            pieceSize=choiceSelector(3);
        }*/
        printf("Dans quelle colonne voulez-vous la placer\n(Faire un choix entre 1 et 3) -> ");
        column=choiceSelector(3)-1;
        printf("Dans quelle ligne voulez-vous la placer\n(Faire un choix entre 1 et 3) -> ");
        row=choiceSelector(3)-1;
        if (pieceSize>get_piece_size(game, row, column)){
            printf("taille de la piece à la case souhaitée : %d\n", get_piece_size(game, row, column));
            if (place_piece(game, x, SMALL, row, column))
                printf("pièce placée avec succès\n");
            printf("test\n");
        }
        else
        {
            printf("Impossible de placer la pièce à l'emplacement voulu");
        }
        affichagePlateau(game);
    }
}