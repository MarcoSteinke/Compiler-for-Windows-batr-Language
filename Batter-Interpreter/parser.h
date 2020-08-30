#ifndef batr_parser
#define batr_parser

#include "error.h"
#include "parser.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

unsigned short find_method(char* method_name, FILE* source_file);

#endif