#ifndef list
#define list

#include <stdio.h>
#include <stdlib.h>

struct string_list {
    size_t size;
    size_t MAX_STRING_LENGTH;
    char** elements;
};

typedef struct string_list string_list;

void dump(string_list* string_list);

string_list* create();

void insert(string_list* string_list, char* string);

#endif