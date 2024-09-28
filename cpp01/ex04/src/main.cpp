#include "Sed.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Error: Number of parameters must be 3 (filename, s1, "
			 "s2)." << std::endl;
		return (1);
	}
	Sed sed(argv);
	sed.checks();
	sed.createNewFile();
}
