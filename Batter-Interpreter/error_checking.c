#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_checking.h"
#include "main.h"
#include "error.h"

int check_file_type(char source_file_name[])
{
    index _index = 0;
    size_t file_name_length = strlen(source_file_name);
    char* result = malloc(sizeof(char) * file_name_length);

    for(int i = 0; i < file_name_length; i++)
    {
        if(*(source_file_name + i) == '.')
        {
            _index = i;
            break;
        }
    }

    char file_type[5];

    for(int i = _index; i < file_name_length; i++)
    {
        if(i - _index <= 4) {
            file_type[i - _index] = source_file_name[i];
        } else
        {
            return -1;
        }
    }

    char* compare_string;
    strcpy(compare_string, file_type);

    printf("%s", compare_string);
    if(strcmp(compare_string, ".batr") == 0)
    {
        free(compare_string);
        return 0;
    } else
    {
        free(compare_string);
        return -1;
    }

    free(compare_string);
    return 0;
}

int check_for_module(FILE* source_file) {

    char command[20];
    char parameter[60];

	if (source_file != NULL)
	{
		fscanf(source_file, "%s %s", command, parameter);

        if(command == NULL || parameter == NULL)
        {
            print_error("ERROR in line 0: There was no module defined!");
            fclose(source_file);
            return -1;
        } else 
        {
            printf("%s %s\n", command, parameter);
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