#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "error_checking.h"

void print_error(std::string &error_msg) {

    const std::string prefix = "BATR: ";

    std::cout << prefix << error_msg << "\n";
}

int check_for_module(std::string &source_file_name) {

    std::ifstream source_file(source_file_name);
    std::string line;

	if (source_file.is_open() )
	{
		std::getline(source_file, line);

        if(line.find("module") < 0 ) {
            print_error("ERROR in line 0: There was no module defined!");
            return -1;
        }
	}

    source_file.close();

    return 0;
}