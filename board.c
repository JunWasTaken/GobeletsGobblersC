#include "board.h"

/**
 * \file board.c
 *
 * \brief Source code associated with \ref board.h
 *
 * \author You?
 */

/**
 * @brief The board of the game, define it as you wish.
 */

typedef struct{
	player content[DIMENSIONS]; //Tableau de joueur à 3 cases : case 0 -> petite pièce, case 1 -> pièce moyenne, case 2 -> grande pièce 
}cases_s;

typedef struct {
	// TODO: compléter la structure.
	
}board_s;

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
