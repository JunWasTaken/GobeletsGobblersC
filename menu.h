#ifndef _MENU_H_
#define _MENU_H_

#include "board.h"

int choiceSelector(int x);
void TourJeu(player x, board game);

typedef struct{
	int x;
	int y;
} Vector2;

#endif
