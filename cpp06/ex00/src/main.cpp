#include "ScalarConverter.hpp"
#include "Utils.hpp"

void printSpecialCases(std::string input)
{
if (input == "-inf" || input == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
    else if (input == "nan" || input == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }

}
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
            if(literal == "-inf" || literal == "+inf" || literal == "nan" || literal == "nanf" ||
            || literal == "-inff" || literal == "+inff" || literal == "inff")
            printSpecialCases(input);
            else
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
