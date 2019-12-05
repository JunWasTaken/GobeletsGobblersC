#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "affichage.h"

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

/**
 * @brief Saisie les coordonnées d'une case manuellement
 * 
 * @param casePlateau -> la case du plateau à saisir les coordonnées
 */ 
void saisieCoord(coord* casePlateau){
    printf("Saisissez la colonne -> ");
    casePlateau->x = choiceSelector(3);
    printf("Saisissez la ligne -> ");
    casePlateau->y = choiceSelector(3);
}

/**
 * @brief fonction gérant le placement d'une pièce sur le plateau
 * 
 * La fonction commence par demander à l'utilisateur de saisir la taille de la pièce 
 * puis les coordonnées de la case de destination. Elle appelle ensuite la fonction place_piece de board.h.
 * Elle affiche un résultat en fonction du résultat de cette dernière.
 * 
 * @param game -> le plateau sur lequel le pion sera placé
 * @param x -> le jpueur qui est en train de placer le pion
 * @return le plateau modifié
 */ 
board placementPion(board game, player x){ 
    coord caseDestination;
    coord* pcd = &caseDestination;
    int column=0, row=0;
    unsigned int pieceSize=0;
    printf("Quelle taille de pièce voulez-vous jouer ? Petite, Moyenne ou Grande\n(Faire un choix entre 1 et 3) -> ");
    pieceSize=choiceSelector(3);
    while(!get_nb_piece_in_house(game, x, pieceSize)){
        printf("Veuillez faire un choix valide\n");
        pieceSize=choiceSelector(3);
    }
    /*printf("Dans quelle colonne voulez-vous la placer\n(Faire un choix entre 1 et 3) -> ");
    column=choiceSelector(3)-1;

    printf("Dans quelle ligne voulez-vous la placer\n(Faire un choix entre 1 et 3) -> ");
    row=choiceSelector(3)-1;*/

    printf("Saisir la case de destination\n");
    saisieCoord(pcd);
        
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
    return game;
}

/**
 * @brief fonction gérant le déplacement des pions
 * 
 * La fonction demande d'abord à l'utilisateur de saisir les coordonnées de la case à prendre le pion,
 * elle lui demande ensuite de saisir les coordonnées de destination. 
 * 
 * Elle appelle la fonction move_piece de board.h et affiche un commentaire correspondant au résultat de cette dernière
 * 
 * @param game -> le plateau que nous allons utiliser pour déplacer les pièces 
 * @param x -> le joueur dont c'est le tour, il est utilisé pour voir si la pièce à la case choisie lui appartient bien
 * 
 * @return le plateau modifié
 */
board deplacementPion(board game, player x){
    coord caseInitiale, caseFinale;
    coord* pci = &caseInitiale;
    coord* pcf = &caseFinale;
    int res=0;
    printf("De quelle case voulez-vous saisir la pièce ?\n");
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
    return game;
}

void TourJeu(player x, board game){
    int choix = 0, column, row;
    unsigned int pieceSize=0; 

    affichagePlateau(game);
    printf("C'est au tour du joueur %d de jouer ;)\n", x);
    printf("Que voulez-vous faire ?\n1-Placer un pion\n2-Déplacer un pion\n");
    choix = choiceSelector(2);
        
    switch (choix){
        case 1:
            game = placementPion(game, x);
        break;
        case 2:
            game = deplacementPion(game, x);
        break;
    }
}

void Partie(player x, player y, board game){
    player current = x, winner=0;
    int cpt = 0;
    do{
        TourJeu(current, game);
        current = next_player(current);
        winner=get_winner(game);
    }while (!(winner));
    affichagePlateau(game);
    if (winner!=0)
        printf("C'est fini, le joueur %d a gagné :D\n", winner);
}