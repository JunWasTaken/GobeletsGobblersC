#include <stdlib.h>
#include <stdio.h>
#include "board.h"

/**
 * \file board.c
 *
 * \brief Source code associated with \ref board.h
 *
 * \author Clément Denos, Paul Morin
 */

/**
 * @brief A place of the board that will hold pieces
 * 
 * Contains an array of size 3, to hold small, medium, and large pieces.
 * Any new piece added to the place will be placed in the corresponding array element,
 * which will only hold the player's number.
 */
typedef struct{
	player content[3];
} place;

/**
 * @brief A house which holds a player's available pieces.
 */
typedef struct{
	player joueur;
	int nbPieces[3];
} house;

/**
 * @brief The board of the game, contains an array of places to hold pieces, and both players' houses.
 */
struct board_s{
	place gameBoard[DIMENSIONS][DIMENSIONS];
	house house[2];
};

board new_game(){ 
	board new_board = malloc(sizeof(struct board_s));
	for (int i=0; i<DIMENSIONS; i++){ 					//lines
		for (int j=0; j<DIMENSIONS; j++){ 				//columns
			for (int k=0; k<DIMENSIONS; k++){ 			//places contents
				new_board->gameBoard[i][j].content[k] = NO_PLAYER; 	//initializes all piece sizes in the place as empty
			}
		}
	}
	for (int j=0; j<2; j++){							//house definition
		new_board->house[j].joueur = PLAYER_1+j;
		for (int i=0; i<3; i++){
			new_board->house[j].nbPieces[i] = 2;		//initializes house content to 2 of each size
		}
	}
	return new_board;
}

size get_piece_size(board game, int row, int column){
	size sMax = NONE;
	place c = game->gameBoard[row][column];

	for (int i = 0; i < 3; i++){
		if (c.content[i] != NO_PLAYER){
			sMax = i+1;							//finds the highest size piece in the place
		}
	}
	return sMax;
}

player get_place_holder(board game, int row, int column){
	place c = game->gameBoard[row][column];
	size pSize = get_piece_size(game, row, column)-1;

	if (pSize == -1)
		pSize = NONE;
	return c.content[pSize];				//finds the owner of the highest size piece
}

int get_nb_piece_in_house(board game, player checked_player, size piece_size){
	int nbPieces = 0;
	if (checked_player != game->house[0].joueur && checked_player != game->house[1].joueur){
		printf ("Le joueur saisi est invalide");
	}else
		nbPieces = game->house[checked_player-1].nbPieces[piece_size-1];
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
		game->gameBoard[line][column].content[piece_size-1] = current_player;
		game->house[current_player-1].nbPieces[piece_size-1]--;
		returnValue = 0;
	}

	return returnValue;
}

int move_piece(board game, int source_line, int source_column, int target_line, int target_column){
	int returnValue;
	size sourceSize = get_piece_size(game, source_line, source_column);
	if (!sourceSize)
		returnValue = 1;
	else if (get_piece_size(game, target_line, target_column) >= sourceSize)
		returnValue = 2;
	else if (source_line >=3 || source_column >= 3 || target_line >= 3 || target_column >=3)
		returnValue = 3;
	else
	{
		game->gameBoard[target_line][target_column].content[sourceSize-1] = game->gameBoard[source_line][source_column].content[sourceSize-1];
		game->gameBoard[source_line][source_column].content[sourceSize-1] = NO_PLAYER;
		returnValue = 0;
	}
	return returnValue;
}

player get_winner(board game){
	player winner = NO_PLAYER;

	for (int i = 0; i < 3; i++){		
		if ((get_place_holder(game, i, 0) != NO_PLAYER) && (get_place_holder(game, i, 0) == get_place_holder(game, i, 1)) && (get_place_holder(game, i, 1) == get_place_holder(game, i, 2))){	//lines check
			if (winner == next_player(get_place_holder(game, i, 0)))	//if there's already a winner and it's not the same one...
				winner = NO_PLAYER;						//draw : no winner yet
			else
				winner = get_place_holder(game, i, 0); 	//else the player who owns the line wins
		}
		
		if ((get_place_holder(game, 0, i) != NO_PLAYER) && (get_place_holder(game, 0, i) == get_place_holder(game, 1, i)) && (get_place_holder(game, 1, i) == get_place_holder(game, 2, i))){	//columns check
			if (winner == next_player(get_place_holder(game, 0, i)))
				winner = NO_PLAYER;						
			else
				winner = get_place_holder(game, 0, i);
		}
	}

	if ((get_place_holder(game, 0, 0) != NO_PLAYER) && (get_place_holder(game, 0, 0) == get_place_holder(game, 1, 1)) && (get_place_holder(game, 1, 1) == get_place_holder(game, 2, 2))){		//diagonals check
		if (winner == next_player(get_place_holder(game, 0, 0)))
			winner = NO_PLAYER;						
		else
			winner = get_place_holder(game, 0, 0);
	}

	if ((get_place_holder(game, 0, 2) != NO_PLAYER) && (get_place_holder(game, 0, 2) == get_place_holder(game, 1, 1)) && (get_place_holder(game, 1, 1) == get_place_holder(game, 2, 0))){
		if (winner == next_player(get_place_holder(game, 0, 2)))
			winner = NO_PLAYER;						
		else
			winner = get_place_holder(game, 0, 2);
	}

	return winner;
}

player next_player(player current_player){
	return -current_player + 3;			//inverts 1 and 2
}

board copy_game(board original_game){
	board newGame = new_game();

	*newGame = *original_game;

	return newGame;
}

void destroy_game(board game){
	// freeing memory, necessary for memory allocated with malloc (leave as is)
	free(game);
}
