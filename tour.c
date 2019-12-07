#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "affichage.h"
#include "directInput.h"

typedef struct{
    int x;
    int y;
} coord;

int choiceSelector(int x){ 
    int choix;
    int returnValue=0;
    
    do{
        scanf("%d", &choix);
        while(getchar() != '\n');
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
    printf("Saisissez la ligne -> ");
    casePlateau->x = choiceSelector(3);
    printf("Saisissez la colonne -> ");
    casePlateau->y = choiceSelector(3);
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
 * @param pl -> le joueur dont c'est le tour, il est utilisé pour voir si la pièce à la case choisie lui appartient bien
 * @param y -> la ligne de la pièce à déplacer
 * @param x -> la colonne de la pière à déplacer
 * 
 * @return le plateau modifié
 */
board deplacementPion(board game, player pl, int y, int x){
    coord cursor = {0, 0};

    drawCursor(game, 0, 0);

    struct termios oldt;
    char c;
    
    initInputMode(&oldt);

    while((c=getchar()) != '\n'){
        if (c == '\033'){           //Si c'est un escape code
            getchar();              //Enlève le [
            switch(getchar()){      //Le vrai code
                case 'A':
                    if (cursor.y > 0){
                        cursor.y--;
                        drawCursor(game, cursor.y, cursor.x);
                    }
                    break;
                case 'B':
                    if (cursor.y < 2){
                        cursor.y++;
                        drawCursor(game, cursor.y, cursor.x);
                    }
                    break;
                case 'C':
                    if (cursor.x < 2){
                        cursor.x++;
                        drawCursor(game, cursor.y, cursor.x);
                    }
                    break;
                case 'D':
                    if (cursor.x > 0){
                        cursor.x--;
                        drawCursor(game, cursor.y, cursor.x);
                    }
            }
        }
    }

    resetInputMode(&oldt);

    int res = move_piece(game, y, x, cursor.y, cursor.x);
    switch (res){
        case 1:
            printf("Il n'y a pas de pièce à la case initiale\n");
            break;
        case 2:
            printf("La pièce est trop petite pour la case de Destination\n");
            break;
        case 3:
            printf("Entrée illégale : ");
            if (x>3 || x>3)
                printf("Ligne trop longue\n");
            else{
                printf("Colonne trop longue\n");
            }
    }

    return game;
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
    coord cursor = {0, 0};
    int column=0, row=0;
    unsigned int pieceSize=0;

    printPlayer(x);
    drawCursor(game, 0, 0);

    struct termios oldt;
    char c;
    
    initInputMode(&oldt);

    while((c=getchar()) != '\n'){
        if (c == '\033'){           //Si c'est un escape code
            getchar();              //Enlève le [
            switch(getchar()){      //Le vrai code
                case 'A':
                    if (cursor.y > 0){
                        cursor.y--;
                        drawCursor(game, cursor.y, cursor.x);
                    }
                    break;
                case 'B':
                    if (cursor.y < 2){
                        cursor.y++;
                        drawCursor(game, cursor.y, cursor.x);
                    }
                    break;
                case 'C':
                    if (cursor.x < 2){
                        cursor.x++;
                        drawCursor(game, cursor.y, cursor.x);
                    }
                    break;
                case 'D':
                    if (cursor.x > 0){
                        cursor.x--;
                        drawCursor(game, cursor.y, cursor.x);
                    }
            }
        }
    }

    if (get_place_holder(game, cursor.y, cursor.x) != x){      //Placement nouvelle pièce

        printf("Quelle taille de pièce ? Petite (1), Moyenne (2) ou Grande (3) : ");
        
        do{
            do{
                pieceSize = getchar();
            } while (pieceSize != '1' && pieceSize != '2' && pieceSize != '3');
            pieceSize -= '0';
            
            if (!get_nb_piece_in_house(game, x, pieceSize))
                moveCursorUnder(3);
                printf("Vous n'avez plus de pièces de cette taille");
        } while(!get_nb_piece_in_house(game, x, pieceSize));
        resetInputMode(&oldt);
            
        int res = place_piece(game, x, pieceSize, cursor.y, cursor.x);
        switch (res){
            case 2:
                printf("La pièce est trop petite pour être placée\n");
                break;
            case 3:
                printf("Position invalide\n");
        }
    }
    else {
        resetInputMode(&oldt);
        printf(" Selectionnez la case où déplacer la pièce");
        game = deplacementPion(game, x, cursor.y, cursor.x);
    }
    return game;
}


void TourJeu(player x, board game){
    int choix = 0, column, row;
    unsigned int pieceSize=0; 

    printf("\033[2J");                               //ANSI code : efface l'écran
    affichagePlateau(game);
    affichageInventory(game);

    game = placementPion(game, x);
}

void Partie(player x, player y, board game){
    player current = x, winner=0;
    int cpt = 0;
    do{
        TourJeu(current, game);
        current = next_player(current);
        winner=get_winner(game);
    }while (!(winner));

    if (winner!=0)
        printWinner(game, winner);
}