#include "parser.h"
#include "syntax.h"

unsigned short find_method(char* method_name, FILE* source_file)
{
    // setup some variables for iteration throug the source_file
    unsigned short scope_level = 0;
    unsigned short method_mode = 0;
    unsigned short entry_point = 0;
    unsigned short fscanf_state = 0;

    int open = 0;
    int close = 0;

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

                if(syntax_iterator[0] == OPEN_SCOPE && syntax_iterator[1] == CLOSE_SCOPE && scope_level_has_changed == 0)
                {
                    return 0;
                }

                // TODO: add support for {{ }}

                if( syntax_iterator[0] == OPEN_SCOPE )
                {

                    // set a flag if the scope_level has ever changed
                    if(scope_level_has_changed == 0)
                    {
                        scope_level_has_changed++;
                    }

                    scope_level++;
                    open++;

                } 
                else if( syntax_iterator[0] == CLOSE_SCOPE )
                {

                    // set a flag if the scope_level has ever changed
                    if(scope_level_has_changed == 0)
                    {
                        scope_level_has_changed++;
                    }

                    close++;
                    scope_level--;

                }

            }

            if(open != close)
            {
                return 2;
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