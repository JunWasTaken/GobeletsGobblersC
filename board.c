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

/**
 * @brief structure case pour le plateau
 * 
 * @brief content est un tableau de taille DIMENSIONS, chaque case de ce tableau correspond à une taille de pièce. 
 * On stocke dans ces case de tableau les numéros des joueurs à qui la case appartient.
 * exemple : J1 place une pièce moyenne; content[1] contient donc J1
 */
typedef struct{
	player content[DIMENSIONS];
}case_s;

struct board_s{
	// TODO: compléter la structure.
	
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
