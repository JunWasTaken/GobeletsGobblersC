#include "board.h"
#include "tour.h"
#include <stdlib.h>
#include <time.h>

coord selectCase(){
    coord casePlateau;
    srand(time(NULL));
    casePlateau.x = rand()%(3-1)+1;
    casePlateau.y = rand()%(3-1)+1;
    return casePlateau;
}

void tourBot(board game){
    coord casePlateau = selectCase();
    int pieceSize = get_piece_size(game, casePlateau.x, casePlateau.y);
    do{
        if (get_place_holder(game, casePlateau.x, casePlateau.y) != game->house[1].joueur){
            if (pieceSize<3){
                if (get_nb_piece_in_house(game, game->house[1].joueur, pieceSize+1)){
                    place_piece(game, game->house[1].joueur, pieceSize, casePlateau.x, casePlateau.y);
                }
            }
        }else 
            casePlateau = selectCase();
    }while(!place_piece(game, game->house[1].joueur, pieceSize, casePlateau.x, casePlateau.y));
}
