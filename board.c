#include "board.h"

/**
 * \file board.c
 *
 * \brief Source code associated with \ref board.h
 *
 * \author You?
 */

struct cases_s{
	player content[3]; //Tableau de joueurs à 3 cases : case 0 -> petite pièce, case 1 -> pièce moyenne, case 2 -> grande pièce 
};

typedef struct cases_s* cases;

/**
 * @brief The board of the game, define it as you wish.
 */
struct board_s{
	// TODO: compléter la structure.
	cases plateau[DIMENSIONS][DIMENSIONS];
};

board new_game(){ 
	// memory allocation for the board (leave it as is)
	board new_board = malloc(sizeof(struct board_s));
	// TODO: Insérer les traitements que vous voudriez faire.
	return new_board;
}

void destroy_game(board game){
	// freeing memory, necessary for memory allocated with malloc (leave as is)
	free(game);
}
