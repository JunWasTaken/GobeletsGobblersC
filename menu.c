#include <stdio.h>
#include <stdlib.h>

int menu(){
    int choix;
    int returnValue=0;
    printf("Bonjour et bienvenue dans Gobelet Gobblers, que voulez-vous faire ?\n1-Lancer une nouvelle partie\n2-gerer vos sauvegardes\n3-quitter\n");
    do{
        printf("Votre Choix : ");
        scanf("%d", &choix);
        if (choix==1){
            returnValue= 1;
        }else if (choix==2){
            returnValue = 2;
        }else if (choix==3)
            returnValue = 0;
        else
        {
            printf("Veuillez saisir une valeur valide\n");
        }
    }while(choix!=1 && choix!=2 && choix!=3);
    return returnValue;
}