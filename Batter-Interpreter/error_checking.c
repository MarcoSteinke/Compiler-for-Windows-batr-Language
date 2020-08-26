#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_checking.h"

void print_error(char error_msg[]) {

    const char* prefix = "BATR: ";

    printf("%s %s \n", prefix, error_msg);
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
        return -1;
    }

    fclose(source_file);
    return 0;
}