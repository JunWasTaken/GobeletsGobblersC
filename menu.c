#include <stdio.h>
#include <stdlib.h>
#include "board.h"

typedef struct{
    int x;
    int y;
} coord;

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

void saisieCoord(coord* casePlateau){
    (*casePlateau).x = choiceSelector(3);
    (*casePlateau).y = choiceSelector(3);
}

board placementPion(board game, player x){ //fonction gérant le placement d'une pièce sur le plateau
    int column=0, row=0;
    unsigned int pieceSize=0;
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

board deplacementPion(board game, player x){
    coord caseInitiale, caseFinale;
    coord* pci = &caseInitiale;
    coord* pcf = &caseFinale;
    int res=0;
    saisieCoord(pci);
    saisieCoord(pcf);
    res=move_piece(game, caseInitiale.x, caseInitiale.y, caseFinale.x, caseFinale.y);
    switch (res){
        case 0:
            printf("pièce placée avec succès\n");
            break;
        case 1:
            printf("Il n'y a pas de pièce à la case initiale\n");
            break;
        case 2:
            printf("La pièce est trop petite pour la case de Destination\n");
            break;
        case 3:
            printf("Entrée illégale : ");
            if (caseInitiale.x>3 || caseFinale.x>3)
                printf("Ligne trop longue\n");
            else{
                printf("Colonne trop longue\n");
            }
            break; 
    }
    affichagePlateau(game);
}

void TourJeu(player x, board game){
    int choix = 0, column, row;
    unsigned int pieceSize=0; 

    printf("Que voulez-vous faire ?\n1-Placer un pion\n2-Déplacer un pion\n");
    choix = choiceSelector(2);
    switch (choix){
        case 1:
            game = placementPion(game, x);
            break;
        case 2:
            affichagePlateau(game);
            break;
    }
}