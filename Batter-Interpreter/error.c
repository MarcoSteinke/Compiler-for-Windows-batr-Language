#include <stdlib.h>

#include "error.h"

void save_standard()
{
    #ifdef _WINDOWS
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    #endif
}

void set_color_blue()
{
    #ifdef _WINDOWS
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    #endif
}

void set_color_green()
{
    #ifdef _WINDOWS
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    #endif
}

void set_color_red()
{
    #ifdef _WINDOWS
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    #endif
}

void restore_color()
{
    #ifdef _WINDOWS
    SetConsoleTextAttribute(hConsole, saved_attributes);
    #endif
}

void print_error(char error_msg[]) 
{
    // get the console from windows
    #ifdef _WINDOWS
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    #endif

    // save the standard configuration to return to
    save_standard();

    // prefix for error output
    const char* prefix = "BATR: ";
    
    // change terminal color to blue
    set_color_blue();
    printf("%s ", prefix);

    set_color_red();
    printf("[!] ");

    // restore terminal color
    restore_color();
    printf("%s\n", error_msg);

    #ifdef _WINDOWS
    free(hConsole);
    #endif
}
