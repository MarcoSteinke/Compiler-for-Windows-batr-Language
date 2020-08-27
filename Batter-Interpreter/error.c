#include "error.h"

void save_standard()
{
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    
}

void set_color_blue()
{
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
}

void set_color_green()
{
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
}

void set_color_red()
{
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
}

void restore_color()
{
    SetConsoleTextAttribute(hConsole, saved_attributes);
}

void print_error(char error_msg[]) 
{
    // get the console from windows
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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

    free(hConsole);
}