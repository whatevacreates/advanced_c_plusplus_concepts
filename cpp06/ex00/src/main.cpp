#include "ScalarConverter.hpp"
#include "Utils.hpp"


int	main(void)
{
	std::string input;
	while (1)
	{
		std::cout << "Input a desired string to be converted into scalar types. Input exit to end the program." << std::endl;	
		std::getline(std::cin, input);
		if (input == "exit")
			break ;    
		try
		{
			
			ScalarConverter::convert(input);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		catch (...)
		{
			std::cerr << "Unknown exception caught!" << std::endl;
		}
	}
	return (0);
}
