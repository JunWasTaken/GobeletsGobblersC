#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "menu.h"

#define BLEU "\033[0;94m"
#define BLEU_ "\033[1;94m"
#define ROUGE "\033[0;31m"
#define ROUGE_ "\033[1;31m"
#define BLANC "\033[37m"
#define CLEARSCR "\033[2J"


void movePrintCursor(Vector2 pos){
    printf("\033[%d;%df", pos.x, pos.y);
}


void afficheVide(){
    int n = 31;
    int a = 0, b = n/3, c = (2*n)/3, d = n-1;       //Début, 1/3, 2/3, fin : tracé des lignes

    printf(CLEARSCR);                               //ANSI code : efface l'écran
    Vector2 printPos = {5, 20};
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
        printPos.x++;                               //Remplace le '\n' de fin de ligne qui retournerait au début à gauche
        movePrintCursor(printPos);
    }
    printPos.y = 1;
    movePrintCursor(printPos);
}


void drawPiece(player pl, size si, Vector2 pos){

}


void affichagePlateau(board game){
    /*int p;
    for (int i=0; i<DIMENSIONS; i++){
        for (int j=0; j<DIMENSIONS; j++){
            p = get_place_holder(game, i, j);
            if (p == 1)
                printf(BLEU);
            else if (p == 2)
                printf(ROUGE);
            else
                printf(BLANC);

            printf("%d ", get_piece_size(game, i, j));
            
        }
        printf("\n");
    }*/
}
