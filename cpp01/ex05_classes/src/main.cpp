#include "Sed.hpp"

int	main(int argc, char *argv[])
{
    Sed sed(argv);
	if (argc != 4)
	{
		std::cout << "Number of parameters must be 3:";
		std::cout << "a filename, a string and a string. " << std::endl;
		std::exit(1);
	}
	sed.checks();
    sed.createNewFile();
}
