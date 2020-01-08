#include "board.h"
#include "tour.h"
#include <stdlib.h>
#include <time.h>

coord selectCase(){
    coord casePlateau;
    srand(time(NULL));

    casePlateau.x = rand()%3;
    casePlateau.y = rand()%3;

    return casePlateau;
}

void tourBot(board game, player pl){
    coord casePlateau;
    int pieceSize;
    int res;

    do{
        casePlateau = selectCase();
        pieceSize = get_piece_size(game, casePlateau.x, casePlateau.y);

        if (get_place_holder(game, casePlateau.x, casePlateau.y) != pl){
            res = place_piece(game, pl, pieceSize+1, casePlateau.x, casePlateau.y);
        }
    }while(res);
}
