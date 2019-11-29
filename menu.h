#ifndef _MENU_H_
#define _MENU_H_

#include "board.h"

/**
 * @brief fonction permettant de faire des choix allant de 1 à une borne x définie par l'utilisateur
 * 
 * Cette fonction est très utilisée dans le programme puisque l'utilisateur est amenée à faire de nombreux choix
 * 
 * @param x -> un entier définissant la borne
 * @return la valeur choisie par l'utilisateur si elle rentre 
 */
int choiceSelector(int x);


void TourJeu(player x, board game);

#endif
