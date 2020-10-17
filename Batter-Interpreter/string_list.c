#include "string_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string_list* create()
{
    string_list* result = malloc(sizeof(string_list));
    result->size = 0;
    result->MAX_STRING_LENGTH = 20;
    result->elements = malloc(sizeof(char*) * result->MAX_STRING_LENGTH * (result->size + 1));

    return result;
}

void insert(string_list* string_list, char* string)
{
    if(string != NULL)
    {
        string_list->elements[string_list->size] = malloc(sizeof(char) * 20);
        string_list->elements = realloc(string_list->elements, sizeof(char) * string_list->MAX_STRING_LENGTH * (string_list->size + 1) );
        strcpy(string_list->elements[string_list->size++], string);
    }
}

void dump(string_list* string_list)
{
    for(int i = 0; i < string_list->size; i++)
    {
        printf("%s\n", string_list->elements[i]);
    }
}

void delete(string_list* this){
    free(this->elements);
    free(this);
}