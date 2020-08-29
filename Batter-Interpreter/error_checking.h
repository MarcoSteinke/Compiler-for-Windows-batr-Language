#ifndef error_checking
#define error_checking

#include <stdio.h>

int check_for_module(FILE* source_file);

void print_error(char* error_msg);

int check_file_type(char source_file_name[]);

unsigned short find_method(char* method_name, FILE* source_file);

#endif