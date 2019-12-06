#ifndef _AFFICHAGE_H_
#define _AFFICAHGE_H_

#include "board.h"

void afficheVide();
void affichagePlateau(board game);
void affichageInventory(board game);
void printPlayer(player pl);
void drawCursor(board game, int x, int y);

#endif