#ifndef _AFFICHAGE_H_
#define _AFFICAHGE_H_

#include "board.h"

/**
 * @brief Prints a blank board (without pieces)
 */
void printBlank();

/**
 * @brief Prints the board's content
 * 
 * @param game the board from which to get the pieces' information
 */
void printBoard(board game);

/**
 * @brief Prints the 2 players' names and houses on both sides of the board
 * 
 * @param game the board from which to get the houses
 */
void printHouses(board game);

/**
 * @brief Prints a player's number under the board
 * 
 * @param pl the player to print
 */
void printPlayer(player pl);

/**
 * @brief Prints the number of the winner at the end of the game
 * 
 * @param game the game that is won
 * @param pl the player who won
 */
void printWinner(board game, player pl);

/**
 * @brief Places the print cursor under the board
 * 
 * @param n the number of lines under the board to place the cursor at
 */
void moveCursorUnder(int n);

/**
 * @brief Draws the input cursor on the board
 * 
 * @param x the board's line onto which to draw the cursor
 * @param y the board's column
 */
void drawCursor(board game, int x, int y);

#endif