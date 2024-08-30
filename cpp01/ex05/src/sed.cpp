#include "Sed.hpp"

void	checks(int argc, char *argv[], std::ifstream &oldFile)
{
	if (argc != 4)
	{
		std::cout << "Number of parameters must be 3:";
		std::cout << "a filename, a string and a string. " << std::endl;
		std::exit(1);
	}
	try
	{
		oldFile.open(argv[1], std::ios::in);
		if (!oldFile.good())
			throw "cannot open a file";
		// Process the file here

		oldFile.close();
	}
	catch (const char *errMsg)
	{
		std::cerr << "Error2: " << errMsg << std::endl;
		oldFile.close();
		std::exit(1);
	}
}