#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "tour.h"


int main(){
    board game;

    printf(CLEARSCR);                   //Clears shell
    printf("\033[8;32;130t");           //Sets shell window size to (32, 130)
    printf("\033[1;1f");                //Moves cursor to (1,1)

    printf("\n   %s   ___        _      _      _        _                   %s_      _      _\n", BLEU, ROUGE);
    printf("   %s  / _ \\ ___  | |__  | |__  | |  ___ | |_    %s__ _   ___  | |__  | |__  | |  ___  _ __  ___ \n", BLEU, ROUGE);
    printf("   %s / /_\\// _ \\ | '_ \\ | '_ \\ | | / _ \\| __|  %s/ _` | / _ \\ | '_ \\ | '_ \\ | | / _ \\| '__|/ __|\n", BLEU, ROUGE);
    printf("   %s/ /_\\\\| (_) || |_) || |_) || ||  __/| |_  %s| (_| || (_) || |_) || |_) || ||  __/| |   \\__ \\\n", BLEU, ROUGE);
    printf("   %s\\____/ \\___/ |_.__/ |_.__/ |_| \\___| \\__|  %s\\__, | \\___/ |_.__/ |_.__/ |_| \\___||_|   |___/\n", BLEU, ROUGE);
    printf("   %s                                           |___/%s\n", ROUGE, BLANC);

    printf("\n     Appuyez sur Entrée pour commencer");

    getchar();

    game = new_game();
    playGame(game);
    //playGameBot(game);
    destroy_game(game);

    return 0;
}