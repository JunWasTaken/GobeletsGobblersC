#include <stdio.h>
#include <stdlib.h>

int menu(){
    int choix;
    int returnValue=0;

    printf("Bonjour et bienvenue dans Gobelet Gobblers, que voulez-vous faire ?\n1-Lancer une nouvelle partie\n2-gerer vos sauvegardes\n3-quitter\n");
    
    do{
        printf("Votre Choix : ");
        scanf("%d", &choix);
        if (choix >= 1 && choix <= 3){
            returnValue = choix%3;
        }
        else
        {
            printf("Veuillez saisir une valeur valide\n");
        }
    }while(choix < 1 && choix > 3);
    
    return returnValue;
}