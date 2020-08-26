#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "error_checking.h"

int find_symbol(char* string, char symbol)
{
    for (size_t i = 0; i < strlen(string); i++)
    {
        if(string[i] == symbol)
        {
            return i;
        }
    }
    return -1;
}

char* cut_file_ending(char* file_name)
{
    index _index = 0;
    size_t file_name_length = strlen(file_name);
    char* result = malloc(sizeof(char) * file_name_length);

    for(int i = 0; i < file_name_length; i++)
    {
        if(*(file_name + i) == '.')
        {
            _index = i;
            break;
        }
    }

    file_name[_index] = '\0';
    strcpy(result, file_name);

    return result;
}

int main(int argc, char const *argv[])
{
    char* source_file_name = malloc(sizeof(char) * 20);
    char* compiled_file_name = malloc(sizeof(char) * 20);

    if(argc > 0) {

        if(argc == 2) {

            // copy the source file's name from the args
            strcpy(source_file_name, argv[1]);

            // remove file ending from source_file_name and store it into compiled_file_name
            strcpy(compiled_file_name, cut_file_ending(source_file_name));

            strcat(compiled_file_name, ".bat");

            printf("%s\n", compiled_file_name);

        } if(argc > 2) {

            // used later for commands during compilation
            // if arg == something  

            if(argc == 3) {
                strcpy(compiled_file_name, argv[2]);
                strcat(compiled_file_name, ".bat");

                printf("%s %s\n", source_file_name, compiled_file_name);
            }          
        }
    }

    FILE* source_file;
    source_file = fopen(source_file_name, "r+");

    int state = check_for_module(source_file);

    if(state == -1)
    {
        free(source_file);
        free(source_file_name);
        free(compiled_file_name);
    }
} 
