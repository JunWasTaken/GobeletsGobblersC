#ifndef _TOUR_H_
#define _TOUR_H_

#include "board.h"

#define BLEU "\033[38;5;39m"
#define ROUGE "\033[38;5;160m"
#define BLANC "\033[37m"
#define CLEARSCR "\033[2J"


/**
 * @brief A coordinate structure, holds x and y positions.
 * 
 * Mainly used to move the shell cursor.
 */
typedef struct{
	int x; 
	int y;
} coord;


/**
 * @brief The main function, handles the game's turns.
 * 
 * @param game the board on which to play the game
 */
void playGame(board game);

void playGameBot(board game);

#endif
