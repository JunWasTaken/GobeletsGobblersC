#include <stdio.h>
#include <termios.h>            //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>     		//STDIN_FILENO


void initInputMode(struct termios *oldt){  
    static struct termios newt;

    /*tcgetattr fetches the terminal's attributes
    STDIN_FILENO copies them into oldt*/
    tcgetattr(STDIN_FILENO, oldt);
    newt = *oldt;

    /*ICANON enables the usual whole-line input
    so it gets disabled
    ECHO is disabled too to stop the inputs from being displayed*/
    newt.c_lflag &= ~(ICANON | ECHO);          

    /*tcsetattr writes attributes into the terminal
    TCSANOW allows it to be done instantly*/
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void resetInputMode(struct termios *oldt){
    //Resets the terminal's old attributes
	tcsetattr(STDIN_FILENO, TCSANOW, oldt);
}


/*      --MAIN EXAMPLE--
int main(){
	
	static struct termios oldt;
	char c;
	initInputMode(&oldt);

    while((c=getchar()) != '\n'){
        if (c == '\033'){               //If the input is an escape code
            getchar();                  //Removes the [
            switch(getchar()){          //Gets the actual code
                case 'A':
                    printf("up");
                    break;
                case 'B':
                    printf("down");
                    break;
                case 'C':
                    printf("right");
                    break;
                case 'D':
                    printf("left");
            }
        }
    }
        

	resetInputMode(&oldt);   


    return 0;
}
*/