#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

typedef struct{
	int x;
	int y;
} Vector2;

void movePrintCursor(Vector2 pos){
    printf("\033[%d;%df", pos.x, pos.y);
}

void afficheVide(){
    int n = GRID_SIZE;
    int a = 0, b = n/3, c = (2*n)/3, d = n-1;       //Début, 1/3, 2/3, fin : tracé des lignes

    printf(CLEARSCR);                               //ANSI code : efface l'écran
    Vector2 printPos = {STARTX, STARTY};
    movePrintCursor(printPos);                      //Déplacement du curseur (coin sup gauche)

    int angleCpt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int ti = (i == a || i == b || i == c || i == d);
            int tj = (j == a || j == b || j == c || j == d);
            if (!ti && !tj){
                printf("  ");
            }
            else {
                if (ti && tj){
                    switch(angleCpt){
                        case 0:
                            printf("┌─");
                            break;
                        case 1:
                        case 2:
                            printf("┬─");
                            break;
                        case 3:
                            printf("┐");
                            break;
                        case 4:
                        case 8:
                            printf("├─");
                            break;
                        case 5:
                        case 6:
                        case 9:
                        case 10:
                            printf("┼─");
                            break;
                        case 7:
                        case 11:
                            printf("┤");
                            break;
                        case 12:
                            printf("└─");
                            break;
                        case 13:
                        case 14:
                            printf("┴─");
                            break;
                        case 15:
                            printf("┘");
                    }

                    angleCpt++;
                }
                else {
                    if (tj)
                        printf("│ ");               //Lignes verticales
                    else if (ti)
                        printf("──");               //Lignes horizontales
                }
            }
        }
        printPos.x++;                               //Remplace le '\n' de fin de ligne (qui retournerait au début à gauche)
        movePrintCursor(printPos);
    }
    printPos.y = 1;
    movePrintCursor(printPos);
}


void drawCircle(int x, int y, int r, int width){
    float mid = width / 2;
    for (int i = 0; i < width+1; i++) {
		for (int j = 0; j < width*2; j++) {
		    float x = mid - j/2, y = mid - i + 1;

			if (sqrt(x * x + y * y) <= r) {
				printf("█");
			}
			else{
				printf(" ");
			}
		}
        movePrintCursor((Vector2){x+i, y});
	}
}


void drawPiece(player pl, size siz, int row, int column){
    int width = (GRID_SIZE-4)/3;

    Vector2 pos;
    pos.x = 1 + STARTX + (row * GRID_SIZE)/3;
    pos.y = 2 + STARTY + (column * GRID_SIZE * 2)/3;

    if (column > 1)
        pos.y--;
    
    movePrintCursor(pos);

    if (pl == 1)
        printf(BLEU);
    else
        printf(ROUGE);

    if (siz == LARGE)
        drawCircle(pos.x, pos.y, width/2, width);
    else if (siz == MEDIUM)
        drawCircle(pos.x+1, pos.y+1, (width-2)/2, width-2);
    else if (siz == SMALL)
        drawCircle(pos.x+2, pos.y+3, (width-4)/2, width-4);

    movePrintCursor((Vector2){STARTX + GRID_SIZE});         //Retour en dessous du plateau
    printf(BLANC);
}


void affichagePlateau(board game){
   afficheVide();

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (get_piece_size(game, i, j) != NONE)
                drawPiece(get_place_holder(game, i, j), get_piece_size(game, i, j), i, j);
        }
    }
}
