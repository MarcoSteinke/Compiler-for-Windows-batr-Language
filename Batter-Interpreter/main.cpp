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
            compiled_file_name = source_file_name.substr(0, index);

            std::cout << compiled_file_name << "\n";
        } if(argc > 2) {

            // used later for commands during compilation
            // if arg == something  

            if(argc == 3) {
                source_file_name = argv[1];
                compiled_file_name = argv[2];

                std::cout << source_file_name << " " << compiled_file_name << "\n";
            }          
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
