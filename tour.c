#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "affichage.h"
#include "directInput.h"


typedef struct{
    int x;
    int y;
} coord;

/**
 * @brief Waits for user inputs to move the game cursor, in order to place or move a piece.
 * 
 * Uses directInput.c to initialize real-time single character input.
 * 
 * Requires a struct termios to be created 
 * and InitInputMode to be called on it beforehand.
 * 
 * ResetInputMode must be called on the termios once a correct input is received,
 * to restore normal whole-line input.
 */
void cursorInput(board game, coord *cursor){
    char c;
    while((c=getchar()) != '\n'){
        if (c == '\033'){               //If the input is an escape code
            getchar();                  //Removes the [
            switch(getchar()){          //Gets the actual code
                case 'A':
                    if (cursor->y > 0){
                        cursor->y--;
                        drawCursor(game, cursor->y, cursor->x);
                    }
                    break;
                case 'B':
                    if (cursor->y < 2){
                        cursor->y++;
                        drawCursor(game, cursor->y, cursor->x);
                    }
                    break;
                case 'C':
                    if (cursor->x < 2){
                        cursor->x++;
                        drawCursor(game, cursor->y, cursor->x);
                    }
                    break;
                case 'D':
                    if (cursor->x > 0){
                        cursor->x--;
                        drawCursor(game, cursor->y, cursor->x);
                    }
            }
        }
    }
}

/**
 * @brief Moves a piece to another place
 * 
 * The function is called when a player selects one of his own pieces with the game cursor
 * and then uses that cursor again to select the target place
 * 
 * move_piece is then called and an error message is displayed if the piece can't be moved.
 * 
 * @param game the board in which the piece is moved
 * @param pl the player who is trying to move a piece
 * @param y the line of the piece to move
 * @param x the column of the piece to move
 * 
 */
void startMovePiece(board game, player pl, int y, int x){
    coord cursor = {0, 0};

    drawCursor(game, 0, 0);

    struct termios oldt;
    
    initInputMode(&oldt);

    do{
        cursorInput(game, &cursor);

        if (x == cursor.x && y == cursor.y){
            moveCursorUnder(2);
            printf("Veuillez choisir une case différente                          ");
        }
        else if (get_piece_size(game, cursor.y, cursor.x) >= get_piece_size(game, y, x)){
            moveCursorUnder(2);
            printf("Cette pièce est trop grosse                                  ");
        }
    } while((x == cursor.x && y == cursor.y) || (get_piece_size(game, cursor.y, cursor.x) >= get_piece_size(game, y, x)));

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
            if (x>3 || cursor.x>3)
                printf("Ligne trop longue\n");
            else{
                printf("Colonne trop longue\n");
            }
    }
}

/**
 * @brief Places or starts moving a piece
 * 
 * The function uses the game input cursor to select a place.
 * 
 * If the place is empty or occupied by another player's piece,
 * it will try to place a new one.
 * 
 * If the place contains a piece owned by the player, it will try to move it.
 * 
 * An error message may be displayed if something goes wrong.
 * 
 * @param game the board on which the piece will be placed
 * @param pl the player trying to place or move a piece
 * 
 */ 
void tryPlacePiece(board game, player pl){ 
    coord cursor = {0, 0};
    unsigned int pieceSize=0;

    printPlayer(pl);
    drawCursor(game, 0, 0);

    struct termios oldt;
    
    initInputMode(&oldt);

    int pSize, possible = 1, otherColor;
    do {
        cursorInput(game, &cursor);

        otherColor = (get_place_holder(game, cursor.y, cursor.x) != pl);
        if (otherColor){
            pSize = get_piece_size(game, cursor.y, cursor.x);
            if (pSize == 3){
                possible = 0;
            }
            else {
                possible = 0;
                for (int i = pSize+1; i <= 3; i++){
                    if (get_nb_piece_in_house(game, pl, i) > 0)
                        possible = 1;
                }
            }

            if (!possible){
                moveCursorUnder(2);
                printf("Vous ne pouvez rien placer sur cette pièce                           ");
            }
        }
        else{
            possible = 1;
        }

    } while (!possible);

    if (otherColor){			//Places new piece

        printf("Quelle taille de pièce ? Petite (1), Moyenne (2) ou Grande (3)       ");
        
        int res;
        do{
            do{
                pieceSize = getchar();
            } while (pieceSize != '1' && pieceSize != '2' && pieceSize != '3');
            pieceSize -= '0';

            res = place_piece(game, pl, pieceSize, cursor.y, cursor.x);
            switch (res){
                case 1:
                    moveCursorUnder(2);
                    printf("Vous n'avez plus de pièces de cette taille                           ");
                    break;
                case 2:
                    moveCursorUnder(2);
                    printf("Choisissez une pièce plus grande                                     ");
            }
            
            
        } while(res);
        resetInputMode(&oldt);
    }
    else {
        resetInputMode(&oldt);
        printf(" Selectionnez la case où déplacer la pièce");
        startMovePiece(game, pl, cursor.y, cursor.x);
    }
}


void gameTurn(player x, board game){
    printf("\033[2J");                               //ANSI code : clears screen
    affichagePlateau(game);
    affichageInventory(game);

    tryPlacePiece(game, x);
}

void playGame(board game){
    player current = PLAYER_1, winner = 0;
    do{
        gameTurn(current, game);
        current = next_player(current);
        winner = get_winner(game);
    }while (!(winner));

    if (winner != NO_PLAYER)
        printWinner(game, winner);
}