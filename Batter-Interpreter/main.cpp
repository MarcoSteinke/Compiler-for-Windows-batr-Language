#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
	std::ifstream source_file("hallo.batr");
	std::ofstream compiled_file("hallo.bat");

    std::string line;

	if (source_file.is_open() )
	{
		while( std::getline(source_file, line) )
	}
} 
