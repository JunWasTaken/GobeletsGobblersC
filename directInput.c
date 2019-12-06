#include <stdio.h>
#include <termios.h>            //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>     		//STDIN_FILENO


void initInputMode(struct termios *oldt){  
    static struct termios newt;

    /*tcgetattr récupère les attributs du terminal
    STDIN_FILENO permet de les copier dans oldt*/
    tcgetattr(STDIN_FILENO, oldt);
    newt = *oldt;

    /*ICANON permet normalement de gérer les entrées une ligne à la fois
    donc le désactive
    et ECHO aussi pour pas afficher les entrées*/
    newt.c_lflag &= ~(ICANON | ECHO);          

    /*Ecriture des attributs dans le terminal
    TCSANOW permet de les écrire immédiatement*/
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

int resetInputMode(struct termios *oldt){
    /*Réinitialise les anciens attributs du terminal*/
	tcsetattr(STDIN_FILENO, TCSANOW, oldt);
}


/*
int main(){
	
	static struct termios oldt;
	char c;
	initInputMode(&oldt);

    while((c=getchar()) != '\n'){
        if (c == '\033'){           //Si c'est un escape code
            getchar();              //Enlève le [
            switch(getchar()){      //Le vrai code
                case 'A':
                    printf("haut");
                    break;
                case 'B':
                    printf("bas");
                    break;
                case 'C':
                    printf("droite");
                    break;
                case 'D':
                    printf("gauche");
            }
        }
    }
        

	resetInputMode(&oldt);   


    return 0;
}
*/