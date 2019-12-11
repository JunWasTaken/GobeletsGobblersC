#include "board.h"

/**
 * \file board.c
 *
 * \brief Source code associated with \ref board.h
 *
 * \author You?
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
} case_s;

typedef struct{
	player joueur;
	int nbPieces[3];
}house;

/**
 * @brief The board of the game, define it as you wish.
 */
struct board_s{
	case_s plateau[DIMENSIONS][DIMENSIONS];
	house house[2];
};

board new_game(){ 
	board new_board = malloc(sizeof(struct board_s));

	// TODO: Insérer les traitements que vous voudriez faire.
	
	return new_board;
}

void destroy_game(board game){
	// freeing memory, necessary for memory allocated with malloc (leave as is)
	free(game);
}
