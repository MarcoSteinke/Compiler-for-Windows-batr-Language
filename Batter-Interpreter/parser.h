#ifndef batr_parser
#define batr_parser

#include "error.h"
#include "parser.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "string_list.h"
#include "main.h"

unsigned short find_method(char* method_name, FILE* source_file);

unsigned short interpret(
    FILE* source_file, 
    index* line_counter, 
    string_list* interpreted_bat_code, 
    string_list* error_list
);

const unsigned short MAX_LINE_LENGTH = 120;

#endif