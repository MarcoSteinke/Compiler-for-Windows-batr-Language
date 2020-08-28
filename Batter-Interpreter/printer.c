#include <stdio.h>
#include <string.h>
#include "error.h"
#include "printer.h"

void print_to_console(char* string)
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

    // restore terminal color
    restore_color();
    printf("%s\n", string);

    free(hConsole);
}