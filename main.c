#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "tour.h"

void menu();

int main(){
    menu();
    return 0;
}

void menu(){
    board plateau;
    player J1 = 1;
    player J2 = 2;
    int x=0;
    printf("Bonjour et bienvenue dans Gobelet Gobblers, que voulez-vous faire ?\n1-Lancer une nouvelle partie\n2-gerer vos sauvegardes\n3-quitter\n");
    x = choiceSelector(3);
    switch(x){
        case 1:
            plateau = new_game();
            printf("plateau cree\n");
            Partie(J1, J2, plateau);
            break;
        case 2:
            printf("chargement des sauvegardes\n");
            break;
        default:
            printf("Au revoir *start playing \"La Marseillaise\" \n");
    }
}