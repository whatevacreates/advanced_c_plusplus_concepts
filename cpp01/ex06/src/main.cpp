#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl harl;
	(void)argv;
	if (argc > 1)
	{
		std::cout << "Type ./harlFilter, without any argumets." << std::endl;
		return (-1);
	}

	std::cout << "This is HarlFilterSystem. " << std::endl;
	std::string input;
	while (1)
	{
		std::cout << "Input: DEBUG, INFO, WARNING, ERROR ";
		std::cout << "or EXIT. EXIT exits the program." << std::endl;
		std::getline(std::cin, input);
		if (input == "EXIT")
			return (-1);
		else if (input != "DEBUG" && input != "INFO" && input != "WARNING"
			&& input != "ERROR")
			std::cout << "This is not right. Try again!" << std::endl;
		else
			harl.complain(input);
	}
}