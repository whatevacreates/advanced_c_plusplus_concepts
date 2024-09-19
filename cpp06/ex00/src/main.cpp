#include "ScalarConverter.hpp"
#include "Utils.hpp"

int	main(void)
{
	std::string input; // Use std::string instead of char to read a full line
	while (1)
	{
		std::cout << "Input a desired string to be converted into scalar types. Input exit to end the program." << std::endl;
		// Use std::getline to read the entire line of input
		std::getline(std::cin, input);
		if (input == "exit")
			break ;
		try
		{
			// Call the static convert method of ScalarConverter
			ScalarConverter::convert(input);
		}
		catch (const std::exception &e)
		{
			// Catch any standard exceptions thrown during the conversion
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		catch (...)
		{
			// Catch any other type of exception
			std::cerr << "Unknown exception caught!" << std::endl;
		}
	}
	return (0);
}
