#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_checking.h"
#include "main.h"
#include "error.h"
#include "syntax.h"

int check_file_type(char source_file_name[])
{
    index _index = 0;
    size_t file_name_length = strlen(source_file_name);
    //char* result = malloc(sizeof(char) * file_name_length);

    for(int i = 0; i < file_name_length; i++)
    {
        if(*(source_file_name + i) == '.')
        {
            _index = ++i;
            break;
        }
    }

    char* file_type = malloc(sizeof(char) * 5);

    for(int i = _index; i < file_name_length; i++)
    {
        if(i - _index <= 4) {
            file_type[i - _index] = source_file_name[i];
        } else
        {
            return -1;
        }
    }

    file_type[file_name_length - _index] = '\0';

    if(strcmp(file_type, "batr") == 0)
    {
        free(file_type);
        return 0;
    } else
    {
        free(file_type);
        return -1;
    }

    free(file_type);
    return 0;
}

int check_for_module(FILE* source_file) {

    char command[20];
    char parameter[60];

	if (source_file != NULL)
	{
		int scanned_values = fscanf(source_file, "%s %s", command, parameter);

        if(scanned_values != 2)
        {
            print_error("ERROR in line 0: There was no module defined!");
            fclose(source_file);
            return -1;
        } else 
        {
            fclose(source_file);
            return 0;
        }
	} else 
    {
        print_error("File not found.");
        return -1;
    }

    fclose(source_file);
    return 0;
}

unsigned short find_method(char* method_name, FILE* source_file)
{
    // setup some variables for iteration throug the source_file
    unsigned short scope_level = 0;
    unsigned short method_mode = 0;
    unsigned short entry_point = 0;
    unsigned short fscanf_state = 0;

    char* tmp = malloc(sizeof(char) * 60);

    // scan each string separated by whitespace
    while( fscanf(source_file, "%s", tmp) != EOF )
    {

        // check if the required method is found:
        if( strcmp(method_name, tmp) == 0)
        {

            // internal iterator
            char* syntax_iterator = malloc(sizeof(char) * 60);

            // main method is found
            method_mode = 1;

            int scope_level_has_changed = 0;

            // iterate through the following part of the file to check if the main-scope is defined correctly
            while( fscanf(source_file, "%s", syntax_iterator) != EOF )
            {
                // if there was a scope and it came back to 0, then there was a valid
                // scoping used in the source_file.
                if(scope_level_has_changed > 0 && scope_level == 0)
                {
                    return 0;
                }

                if(syntax_iterator[0] == OPEN_SCOPE && syntax_iterator[1] == CLOSE_SCOPE && scope_level_has_changed == 0)
                {
                    return 0;
                }

                if( syntax_iterator[0] == OPEN_SCOPE )
                {

                    // set a flag if the scope_level has ever changed
                    if(scope_level_has_changed == 0)
                    {
                        scope_level_has_changed++;
                    }

                    scope_level++;

                } 
                else if( syntax_iterator[0] == CLOSE_SCOPE )
                {

                    // set a flag if the scope_level has ever changed
                    if(scope_level_has_changed == 0)
                    {
                        scope_level_has_changed++;
                    }

                    scope_level--;

                }

            }

            // if there was a scope and it came back to 0, then there was a valid
            // scoping used in the source_file.
            if(scope_level_has_changed > 0 && scope_level == 0)
            {
                return 0;
            }

        }
    }

    return 1;
}