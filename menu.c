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
    printf("\n");
    return returnValue;
}

/*void affichagePlateau(board game){
    for (int i=0; i<DIMENSIONS; i++){
        for (int j=0; j<DIMENSIONS; j++){
            printf("%d ", get_piece_size(game, i, j));
        }
        printf("\n");
    }
}*/

board placementPion(board game, player x){
    printf("x");
}

void TourJeu(player x, board game){
    int choix = 0, column, row;
    unsigned int pieceSize=0; 

    printf("Que voulez-vous faire ?\n1-Placer un pion\n2-Déplacer un pion\n");
    choix = choiceSelector(2);

    if (choix == 1){
        printf("Quelle taille de pièce voulez-vous jouer ? Petite, Moyenne ou Grande\n(Faire un choix entre 1 et 3) -> ");
        pieceSize=choiceSelector(3);
        while(!get_nb_piece_in_house(game, x, pieceSize)){
            printf("Veuillez faire un choix valide\n");
            pieceSize=choiceSelector(3);
        }
        printf("Dans quelle colonne voulez-vous la placer\n(Faire un choix entre 1 et 3) -> ");
        column=choiceSelector(3)-1;

        printf("Dans quelle ligne voulez-vous la placer\n(Faire un choix entre 1 et 3) -> ");
        row=choiceSelector(3)-1;
        
        int res = place_piece(game, x, pieceSize, row, column);
        switch (res){
            case 0:
                printf("Piece placée avec succès\n");
                break;
            case 1:
                printf("Pas assez de pièces de cette taille dans la maison\n");
                break;
            case 2:
                printf("La pièce est trop petite pour être placée\n");
                break;
            case 3:
                printf("Position invalide\n");
        }
        affichagePlateau(game);
    }
}