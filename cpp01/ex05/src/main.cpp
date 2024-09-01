#include "Harl.hpp"

int	main(void)
{
	Harl harl;
	std::cout << "Get to know Harl! ";
	std::string input;
	while (1)
	{
		std::cout << "Input: DEBUG, INFO, WARNING, ERROR ";
		std::cout << "or EXIT. EXIT exits the program." << std::endl;

		std::cin >> input;

		if (input == "EXIT")
			return (-1);
		else if (input != "DEBUG" && input != "INFO" && input != "WARNING"
			&& input != "ERROR")
			std::cout << "This is not right. Try again!" << std::endl;
		else
			harl.complain(input);
	}
}