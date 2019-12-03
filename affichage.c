#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "tour.h"

#define BLEU "\033[0;94m"
#define BLEU_ "\033[1;94m"
#define ROUGE "\033[0;31m"
#define ROUGE_ "\033[1;31m"
#define BLANC "\033[37m"
#define CLEARSCR "\033[2J"

#define GRID_SIZE 25            //Multiple de 6 + 1
#define STARTX 5
#define STARTY 20

void movePrintCursor(Vector2 pos){
    printf("\033[%d;%df", pos.x, pos.y);
}

void afficheVide(){
    int n = GRID_SIZE;
    int a = 0, b = n/3, c = (2*n)/3, d = n-1;       //Début, 1/3, 2/3, fin : tracé des lignes

    printf(CLEARSCR);                               //ANSI code : efface l'écran
    Vector2 printPos = {STARTX, STARTY};
    movePrintCursor(printPos);                      //Déplacement du curseur (coin sup gauche)

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int ti = (i == a || i == b || i == c || i == d);
            int tj = (j == a || j == b || j == c || j == d);
            if (!ti && !tj){
                printf("  ");
            }
            else {
                if (ti && tj){
                    if (j != d)                     //Fin de ligne
                        printf("+-");
                    else
                        printf("+");
                }
                else {
                    if (tj)
                        printf("| ");               //Lignes verticales
                        //printf("%d ", i%10);
                    else if (ti)
                        printf("--");               //Lignes horizontales
                        //printf("%d ", j%10);
                }
            }
        }
        printPos.x++;                               //Remplace le '\n' de fin de ligne (qui retournerait au début à gauche)
        movePrintCursor(printPos);
    }
    printPos.y = 1;
    movePrintCursor(printPos);
}


void drawPiece(player pl, size si, int row, int column){
    int width = (GRID_SIZE-4)/3;

    Vector2 pos;
    pos.x = 1 + STARTX + (row * GRID_SIZE)/3;
    pos.y = 1 + STARTY + (column * GRID_SIZE * 2)/3;

    if (column > 1)
        pos.y--;
    
    movePrintCursor(pos);

    if (pl == 1)
        printf(BLEU);
    else
        printf(ROUGE);

    printf("X");

    movePrintCursor((Vector2){STARTX + GRID_SIZE});         //Retour en dessous du plateau
    printf(BLANC);
}


void affichagePlateau(board game){
    /*
    get_place_holder(game, i, j);
    get_piece_size(game, i, j));
    */

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            drawPiece(PLAYER_1, MEDIUM, i, j);
        }
    }
    //drawPiece(PLAYER_1, MEDIUM, (Vector2){STARTX + GRID_SIZE/3 + 1, STARTY + (GRID_SIZE*2)/3 + 1});
    //drawPiece(PLAYER_1, MEDIUM, (Vector2){STARTX + (GRID_SIZE*2)/3 - 1, STARTY + (GRID_SIZE*4)/3 - 2});
}
