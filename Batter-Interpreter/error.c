#include "error.h"

void print_error(char error_msg[]) 
{

    const char* prefix = "BATR: ";

    printf("%s %s \n", prefix, error_msg);
}