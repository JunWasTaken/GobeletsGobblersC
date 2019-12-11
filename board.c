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
}case_s;

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
	// memory allocation for the board (leave it as is)
	board new_board = malloc(sizeof(struct board_s));
	for (int i=0; i<DIMENSIONS; i++){ //parcours des lignes
		for (int j=0; j<DIMENSIONS; j++){ //parcours des colonnes
			for (int k=0; k<DIMENSIONS; k++){ //parcours du contenu de la case en {i;j}
				new_board->plateau[i][j].content[k]=0; //initialise le contenu de la case à 0 pour les pièces petites, moyennes et grandes
			}
		}
	}
	for (int j=0; j<2; j++){
		new_board->house[j].joueur = PLAYER_1+j;
		for (int i=0; i<3; i++){
			new_board->house[j].nbPieces[i]=2;
		}
	}
	return new_board;
}

player get_place_holder(board game, int line, int column){
	
}

int get_nb_piece_in_house(board game, player checked_player, size piece_size){
	int nbPieces=0;
	if (checked_player != game->house[0].joueur || checked_player != game->house[1].joueur){
		printf ("Le joueur saisi est invalide");
	}else
		nbPieces = game->house[checked_player].nbPieces[piece_size-1];
	return nbPieces;
}

void destroy_game(board game){
	// freeing memory, necessary for memory allocated with malloc (leave as is)
	free(game);
}
