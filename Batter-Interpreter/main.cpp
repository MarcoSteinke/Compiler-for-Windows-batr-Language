#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string source_file_name;
    std::string compiled_file_name;

    if(argc > 0) {

        if(argc == 2) {
            source_file_name = argv[1];
            size_t index = source_file_name.find(".");
            compiled_file_name = source_file_name.substr(index - 1);

            std::cout << compiled_file_name << "\n";
        }
    }

	/*std::ifstream source_file("hallo.batr");
	std::ofstream compiled_file("hallo.bat");

    std::string line;

	if (source_file.is_open() )
	{
		while( std::getline(source_file, line) ) {

        }
	}*/
} 
