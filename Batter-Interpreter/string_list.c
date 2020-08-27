#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_list.h"

string_list* create()
{
    string_list* result = malloc(sizeof(string_list));
    result->size = 0;
    result->MAX_STRING_LENGTH = 20;
    result->elements = malloc(sizeof(char) * result->MAX_STRING_LENGTH * result->size);

    return result;
}

void insert(string_list* string_list, char* string)
{
    if(string != NULL)
    {
        string_list = realloc(string_list, sizeof(char) * string_list->MAX_STRING_LENGTH * (string_list->size + 1) );
        strcpy(*(string_list->elements + string_list->size), string);
    }
}