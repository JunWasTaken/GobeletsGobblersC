#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int choiceSelector(int x){
    int choix;
    int returnValue=0;
    
    do{
        printf("Votre Choix : ");
        scanf("%d", &choix);
        if (choix >= 1 && choix <= 3){
            returnValue = choix%3;
        }
        else
        {
            printf("Veuillez saisir une valeur valide\n");
        }
    }while(choix < 1 || choix > x);
    
    return returnValue;
}

void TourJeu(player x, board game){
    int choix = 0, pieceSize=0, column=0, row=0;
    printf("Que voulez-vous faire ?\n1-Placer un pion\n2-Déplacer un pion\n");
    choix = choiceSelector(2);
    if (choix==1){
        printf("Quelle taille de pièce voulez-vous jouer ? Petite, Moyenne ou Grande\n(Faire un choix entre 1 et 3) -> ");
        pieceSize=choiceSelector(3);
        while(!get_nb_piece_in_house(game, x, pieceSize)){
            printf("Veuillez faire un choix valide");
            pieceSize=choiceSelector(3);
        }
        printf("Dans quelle colonne voulez-vous la placer\n(Faire un choix entre 1 et 3) -> ");
        column=choiceSelector(3);
        printf("Dans quelle ligne voulez-vous la placer\n(Faire un choix entre 1 et 3) -> ");
        row=choiceSelector(3);
        if (pieceSize>get_piece_size(game, column, row))
            place_piece(game, x, pieceSize, row, column);
        else
        {
            printf("Impossible de placer la pièce à l'emplacement voulu");
        }
        
    }
}