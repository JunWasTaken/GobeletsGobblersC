#ifndef _DINPUT_H_
#define _DINPUT_H_
#include <termios.h>

void initInputMode(struct termios *oldt);

int resetInputMode(struct termios *oldt);


#endif