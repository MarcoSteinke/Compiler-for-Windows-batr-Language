#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "error_checking.h"
#include <windows.h>
#include "error.h"

void free_memory(FILE* source_file, char* source_file_name, char* compiled_file_name)
{
    if(source_file != NULL)        free(source_file);
    if(source_file_name != NULL)   free(source_file_name);
    if(compiled_file_name != NULL) free(compiled_file_name);
}

// replication of the (String) indexOf() method from Java
int find_symbol(char* string, char symbol)
{
    // iterate through the string until the symbol occurs.
    for (size_t i = 0; i < strlen(string); i++)
    {
        // if symbol is found, return its index
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

    // iterate through the filename until a . appears
    for(int i = 0; i < file_name_length; i++)
    {
        if(*(file_name + i) == '.')
        {
            _index = i;
            break;
        }
    }

    // copy the filename to a new variable
    strcpy(result, file_name);

    // cut the file ending starting at _index
    result[_index] = '\0';

    return result;
}

int main(int argc, char const *argv[])
{
    // alloc memory for the file names
    char* source_file_name = malloc(sizeof(char) * 20);
    char* compiled_file_name = malloc(sizeof(char) * 20);

    // determine which program call was used
    if(argc > 0) {

        if(argc == 2) 
        {

            // copy the source file's name from the args
            strcpy(source_file_name, argv[1]);

            int res = check_file_type(source_file_name);
            if(res == -1)
            {
                print_error("File is not of the type \".batr\"");
                free_memory(NULL, source_file_name, compiled_file_name);
                return 1;
            }

            // remove file ending from source_file_name and store it into compiled_file_name
            strcpy(compiled_file_name, cut_file_ending(source_file_name));

            strcat(compiled_file_name, ".bat");


        } 
        else if(argc > 2) {

            // used later for commands during compilation
            // if arg == something  

            if(argc == 3) {
                strcpy(compiled_file_name, argv[2]);
                strcat(compiled_file_name, ".bat");

            }          
        }
    }

    // setup the source_file
    FILE* source_file;
    source_file = fopen(source_file_name, "r+");

    // check if a module was defined in the source_file
    int state = check_for_module(source_file);

    // if there was no module, throw an error
    if(state == -1)
    {
        print_error("Stopped the interpretation of:");
        set_color_green();
        printf("           %s\n", source_file_name);
        restore_color();

        free_memory(source_file, source_file_name, compiled_file_name);

        fclose(source_file);

        return 1;
    }

    fclose(source_file);
    free_memory(source_file, source_file_name, compiled_file_name);

    return 0;
} 
