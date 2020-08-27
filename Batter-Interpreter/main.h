#ifndef __main__
#define __main__

int find_symbol(char* string, char symbol);

char* cut_file_ending(char* file_name);

typedef int index;

void free_memory(FILE* source_file, char* source_file_name, char* compiled_file_name);

#endif