#include "ScalarConverter.hpp"
#include "Utils.hpp"

void	printSpecialCases(std::string input)
{
	if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (input == "+inf" || input == "+inff" || input == "inf"
		|| input == "inff")
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

void	checkMaxMin(double value)
{
	std::cout << BOLD << PASTEL_LAVENDER << "CHAR: " << RESET << "impossible" << std::endl;
	std::cout << BOLD << PASTEL_LAVENDER << "INT: " << RESET << "impossible" << std::endl;
	if (value > INT_MAX)
	{
		std::cout << BOLD << PASTEL_LAVENDER << "FLOAT: " << RESET << "inf" << std::endl;
		std::cout << BOLD << PASTEL_LAVENDER << "DOUBLE: " << RESET << "inf" << std::endl;
	}
	else if (value < INT_MIN)
	{
		std::cout << BOLD << PASTEL_LAVENDER << "FLOAT: " << RESET << "-inf" << std::endl;
		std::cout << BOLD << PASTEL_LAVENDER << "DOUBLE: " << RESET << "-inf" << std::endl;
	}
}

bool	checkNumber(const std::string &literal)
{
	size_t	i;
	int		dot_count;

	dot_count = 0;
	if (literal.empty())
	{
		std::cout << "1check" << std::endl;
		return (false);
	}
	i = 0;
	if (!isdigit(literal[i]) && isprint(literal[i]))
	{
		if ((literal.size() == 1 && literal[i] == '-') || (literal.length() > 1
				&& literal[i] != '-'))
		{
			return (false);
		}
		i++;
	}
	for (; i < literal.length(); ++i)
	{
		if (literal[i] == 'f' && !literal[i + 1] && literal.length() > 1)
			return (true);
		if (literal[i] == '.')
			dot_count++;
		if (((!std::isdigit(literal[i]) && literal[i] != '.')
				|| (literal[i] == '.' && !std::isdigit(literal[i + 1]))
				|| (dot_count > 1)))
		{
			return (false);
		}
	}
	return (true);
}

int	main(void)
{
	double	value;
	char	*end;

	std::string input;
	while (1)
	{
		std::cout << B_LAVENDER << BOLD << "Input a desired string to be converted into scalar types. Input exit to end the program:" << RESET << std::endl;
		std::getline(std::cin, input);
		if (input == "exit")
			break ;
		value = strtod(input.c_str(), &end);
		try
		{
			if (value > INT_MAX || value < INT_MIN)
				checkMaxMin(value);
			else if (input == "-inf" || input == "+inf" || input == "nan"
				|| input == "nanf" || input == "-inff" || input == "+inff"
				|| input == "inff" || input == "inf")
				printSpecialCases(input);
			else if (!checkNumber(input))
				std::cout << "wrong input" << std::endl;
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
		input.clear();
	}
	return (0);
}
