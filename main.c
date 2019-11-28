#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "menu.h"

int choiceSelector(int x); 
void TourJeu(player x, board game);

int main(){
    board plateau;
    player J1;
    int x=0;
    printf("Bonjour et bienvenue dans Gobelet Gobblers, que voulez-vous faire ?\n1-Lancer une nouvelle partie\n2-gerer vos sauvegardes\n3-quitter\n");
    x=choiceSelector(3);
    if (x==1){
        plateau = new_game();
        printf("plateau creer\n");
        TourJeu(J1, plateau);
    }else if (x==2){
        printf("chargement des sauvegardes\n");
    }else
    {
        printf("Au revoir *start playing \"La Marseillaise\" \n");
    }
    
    return 0;
}