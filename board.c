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
	for (int i=0; i<DIMENSIONS; i++){ 					//parcours des lignes
		for (int j=0; j<DIMENSIONS; j++){ 				//parcours des colonnes
			for (int k=0; k<DIMENSIONS; k++){ 			//parcours du contenu de la case en {i;j}
				new_board->plateau[i][j].content[k]=0; 	//initialise le contenu de la case à 0 pour les pièces petites, moyennes et grandes
			}
		}
	}
	for (int j=0; j<2; j++){
		new_board->house[j].joueur = PLAYER_1+j;
		for (int i=0; i<3; i++){
			new_board->house[j].nbPieces[i] = 2;
		}
	}
	return new_board;
}

size get_piece_size(board game, int row, int column){
	size sMax = NONE;
	case_s *c = game->plateau[row, column];

	for (int i = 0; i < 3; i++){
		if (c->content[i] != NO_PLAYER){
			if (i > sMax)
				sMax = i+1;
		}
	}
	return sMax;
}

player get_place_holder(board game, int row, int column){
	case_s *c = game->plateau[row, column];
	return c->content[get_piece_size(game, row, column)-1];
}

int get_nb_piece_in_house(board game, player checked_player, size piece_size){
	int nbPieces=0;
	if (checked_player != game->house[0].joueur || checked_player != game->house[1].joueur){
		printf ("Le joueur saisi est invalide");
	}else
		nbPieces = game->house[checked_player].nbPieces[piece_size-1];
	return nbPieces;
}

int place_piece(board game, player current_player, size piece_size, int line, int column){
	int returnValue; 

	if (!(get_nb_piece_in_house(game, current_player, piece_size)))
		returnValue = 1;
	else if (get_piece_size(game, line, column) >= piece_size)
		returnValue = 2;
	else if (line >= 3 || column >= 3)
		returnValue = 3;
	else
	{
		game->plateau[line][column].content[piece_size-1] = current_player;
		returnValue = 0;
	}

	return returnValue;
}

int move_piece(board game, int source_line, int source_column, int target_line, int target_column){
	int returnValue;
	size sourceSize = get_piece_size(game, source_line, source_column);
	if (!sourceSize)
		returnValue = 1;
	else if (get_piece_size(game, target_line, target_column)>=sourceSize)
		returnValue = 2;
	else if (source_line >=3 || source_column >= 3 || target_line >= 3 || target_column >=3)
		returnValue = 3;
	else
	{
		game->plateau[target_line][target_column].content[get_piece_size(game, source_line, source_column)-1] = game->plateau[source_line][source_column].content[get_piece_size(game, source_line, source_column)-1];
		game->plateau[target_line][target_column].content[get_piece_size(game, source_line, source_column)-1] = 0;
		returnValue = 0;
	}
	return returnValue;
}

player get_winner(board game){
	player winner = NO_PLAYER;
	int i = 0;

	for (int i = 0; i < 3; i++){		
		if (get_place_holder(game, i, 0) == get_place_holder(game, i, 1) == get_place_holder(game, i, 2))	//vérification des lignes
			if (winner != NO_PLAYER && winner != get_place_holder(game, i, 0))	//si il y a déjà un gagnant et que c'est pas le même
				winner = NO_PLAYER;						//égalité : pas encore de gagnant
			else
				winner = get_place_holder(game, i, 0);	//le joueur qui a la ligne gagne
		
		if (get_place_holder(game, 0, i) == get_place_holder(game, 1, i) == get_place_holder(game, 2, i))	//vérification des colonnes
			if (winner != NO_PLAYER && winner != get_place_holder(game, 0, i))
				winner = NO_PLAYER;						
			else
				winner = get_place_holder(game, 0, i);	//le joueur qui a la colonne gagne
	}

	return winner;
}

player next_player(player current_player){
	return -current_player + 3;			//inverse 1 et 2
}

void destroy_game(board game){
	// freeing memory, necessary for memory allocated with malloc (leave as is)
	free(game);
}
