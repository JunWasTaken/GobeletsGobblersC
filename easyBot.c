#include "board.h"
#include "tour.h"
#include <stdlib.h>
#include <time.h>

coord selectPlace(){
    coord place;
    srand(time(NULL));

    place.x = rand()%3;
    place.y = rand()%3;

    return place;
}

void stoopBot(board game, player pl){
    coord place;
    int pieceSize;
    int res;

    do{
        place = selectPlace();
        pieceSize = get_piece_size(game, place.x, place.y);

        if (get_place_holder(game, place.x, place.y) != pl){
            res = place_piece(game, pl, pieceSize+1, place.x, place.y);
        }
    }while(res);
}
