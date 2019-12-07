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
    /*
    printf("Bonjour et bienvenue dans Gobblet Gobblers, que voulez-vous faire ?\n1-Lancer une nouvelle partie\n2-gerer vos sauvegardes\n3-quitter\n");
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
            printf("Au revoir.\n");
    }
    */

    /*
    printf("  ________        ___.   ___.    .__            __                    ___.   ___.            .__                         \\n");
    printf(" /  _____/   ____ \\_ |__ \\_ |__  |  |    ____ _/  |_     ____    ____ \\_ |__ \\_ |__    ____  |  |    ____ _______  ______\\n");
    printf("/   \\  ___  /  _ \\ | __ \\ | __ \\ |  |  _/ __ \\\\   __\\   / ___\\  /  _ \\ | __ \\ | __ \\ _/ __ \\ |  |  _/ __ \\\\_  __ \\/  ___/\\n");
    printf("\\    \\_\\  \\(  <_> )| \\_\\ \\| \\_\\ \\|  |__\\  ___/ |  |    / /_/  >(  <_> )| \\_\\ \\| \\_\\ \\\\  ___/ |  |__\\  ___/ |  | \\/\\___ \\ \\n");
    printf(" \\______  / \\____/ |___  /|___  /|____/ \\___  >|__|    \\___  /  \\____/ |___  /|___  / \\___  >|____/ \\___  >|__|  /____  >\\n");
    printf("        \\/             \\/     \\/            \\/        /_____/              \\/     \\/      \\/            \\/            \\/ \n");
    */

   printf(CLEARSCR);
   printf("\033[1;1f");

    printf("\n   %s   ___        _      _      _        _                   %s_      _      _\n", BLEU, ROUGE);
    printf("   %s  / _ \\ ___  | |__  | |__  | |  ___ | |_    %s__ _   ___  | |__  | |__  | |  ___  _ __  ___ \n", BLEU, ROUGE);
    printf("   %s / /_\\// _ \\ | '_ \\ | '_ \\ | | / _ \\| __|  %s/ _` | / _ \\ | '_ \\ | '_ \\ | | / _ \\| '__|/ __|\n", BLEU, ROUGE);
    printf("   %s/ /_\\\\| (_) || |_) || |_) || ||  __/| |_  %s| (_| || (_) || |_) || |_) || ||  __/| |   \\__ \\\n", BLEU, ROUGE);
    printf("   %s\\____/ \\___/ |_.__/ |_.__/ |_| \\___| \\__|  %s\\__, | \\___/ |_.__/ |_.__/ |_| \\___||_|   |___/\n", BLEU, ROUGE);
    printf("   %s                                           |___/%s\n", ROUGE, BLANC);

    printf("\n     Appuyez sur Entrée pour commencer");

    getchar();

    plateau = new_game();
    Partie(J1, J2, plateau);
}