#ifndef error
#define error

#include <stdio.h>
#include "win.h"

// methods to control the windows terminal

void save_standard();

void set_color_blue();

void set_color_green();

void set_color_red();

void restore_color();

void print_error(char error_msg[]);

// setup windows specific environment
#ifdef _WINDOWS
HANDLE hConsole;
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD saved_attributes;
#endif

#endif
