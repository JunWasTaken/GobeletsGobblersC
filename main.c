#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "menu.h"

int menu(); 

int main(){
    board plateau;
    int x = menu();
    if (x==1){
        plateau = new_game();
        printf("plateau creer\n");
    }
    return 0;
}