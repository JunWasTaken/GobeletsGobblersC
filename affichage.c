#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "board.h"

#define BLEU "\033[0;94m"
#define BLEU_ "\033[1;94m"
#define ROUGE "\033[0;31m"
#define ROUGE_ "\033[1;31m"

void color(int textColor, int bgColor){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,bgColor*16+textColor);
}

void affichagePlateau(board game){
    for (int i=0; i<DIMENSIONS; i++){
        for (int j=0; j<DIMENSIONS; j++){
            if (get_place_holder(game, i, j)==1){
                color(3, 0);
                printf("%d ", get_piece_size(game, i, j));
            }else{
                color(12, 0);
                printf(ROUGE"%d ", get_piece_size(game, i, j));
            }
            
        }
        printf("\n");
    }
}
