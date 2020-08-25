#include <iostream>
#include <fstream>

int main()
{
	std::ofstream source_file("hallo.batr");
	std::ofstream compiled_file("hallo.bat");

	if (source_file.is_open() )
	{
		while( std::getline(source_file) )
	}
}