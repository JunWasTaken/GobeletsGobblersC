#ifndef _DINPUT_H_
#define _DINPUT_H_
#include <termios.h>


/**
 * @brief Enables real-time single character input to be used in the shell
 * 
 * @param oldt a pointer to a termios structure
 */
void initInputMode(struct termios *oldt);


/**
 * @brief Resets the shell's usual whole-line input mode
 * 
 * @param oldt a pointer to the termios to reset
 */
int resetInputMode(struct termios *oldt);


#endif