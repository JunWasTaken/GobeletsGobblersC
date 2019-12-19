#ifndef _TOUR_H_
#define _TOUR_H_

#include "board.h"

#define BLEU "\033[38;5;39m"
#define ROUGE "\033[38;5;160m"
#define BLANC "\033[37m"
#define CLEARSCR "\033[2J"

typedef struct{
	int x; 
	int y;
} coord;

/**
 * @brief fonction permettant de faire des choix allant de 1 à une borne x définie par l'utilisateur
 * 
 * Cette fonction est très utilisée dans le programme puisque l'utilisateur est amenée à faire de nombreux choix
 * 
 * @param x -> un entier définissant la borne
 * @return la valeur choisie par l'utilisateur si elle rentre 
 */
int choiceSelector(int x);

/**
 * @brief fonction gérant un tour lors d'une partie, c'est la fonction principale du programme
 * Elle fait appel à toutes les autres fonction de tour.c et de affichage.c
 * 
 * @param game -> le plateau du jeu
 */
void Partie(board game);

#endif
