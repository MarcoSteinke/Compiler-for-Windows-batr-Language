#ifndef error
#define error

#include <stdio.h>
#include <windows.h>

// methods to control the windows terminal

void save_standard();

void set_color_blue();

void set_color_green();

void restore_color();

void print_error(char error_msg[]);

// setup windows specific environment
HANDLE hConsole;
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD saved_attributes;

#endif