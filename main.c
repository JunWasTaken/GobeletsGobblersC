#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "menu.h"

int main(){
    board plateau;
    player J1 = 1;
    printf("Bonjour et bienvenue dans Gobelet Gobblers, que voulez-vous faire ?\n1-Lancer une nouvelle partie\n2-gerer vos sauvegardes\n3-quitter\n");
    int x = choiceSelector(3);
    switch(x){
        case 1:
            plateau = new_game();
            printf("plateau cree\n");
            for (int i=0; i<3; i++){
                TourJeu(J1, plateau);
            }
            break;
        case 2:
            printf("chargement des sauvegardes\n");
            break;
        default:
            printf("Au revoir *start playing \"La Marseillaise\" \n");
    }
    
    return 0;
}