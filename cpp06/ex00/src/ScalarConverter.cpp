

#include "ScalarConverter.hpp"

// Implementation of the convert method
void ScalarConverter::convert(const std::string &literal)
{
	// Check if the literal can be converted to each type and call respective function
	// Try to convert to each type and print results
	toChar(literal);
	toInt(literal);
	toFloat(literal);
	toDouble(literal);
}

// Implementation of conversion functions
char ScalarConverter::toChar(const std::string &literal)
{
	int	value;

	// Check if the literal can be converted to char
	if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
	{
		std::cout << "char: '" << literal[0] << "'" << std::endl;
		return (literal[0]);
	}
	else
	{
        if (literal.length() != 1 && !checkNumber(literal, "char"))
		return (0);
		value = std::strtol(literal.c_str(), NULL, 10);
		if (value >= 0 && value <= 127 && isprint(static_cast<char>(value)))
		{
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
			return (static_cast<char>(value));
		}
	}
	std::cout << "char: impossible" << std::endl;
	return (0);
}
bool ScalarConverter::checkNumber(const std::string &literal, const std::string &scalar_type)
{
	size_t	i;

	if (literal.empty())
	{
		std::cout << scalar_type << ": impossible 1" << std::endl;
		return (false);
	}
	// Check for valid characters in the string: digits and an optional leading minus sign
	i = 0;
	if (literal[i] == '-')
	{
		if (literal.size() == 1)
		{ // String with only '-' is not valid
			std::cout << scalar_type << ": impossible 2" << std::endl;
			return (false);
		}
		i++; // Skip the minus sign
	}
	// Check each character to ensure it's a digit
	for (i = 1; i < literal.length(); ++i)
	{
		if (!std::isdigit(literal[i]))
		{
			std::cout << scalar_type << ": impossible 3" << std::endl;
			return (false);
		}
	}
	return (true);
}
int ScalarConverter::toInt(const std::string &literal)
{
	int	value;

	if (!checkNumber(literal, "int"))
		return (0);
	// Check if the string is a valid integer literal
	try
	{
		// Convert the validated string to an integer
        if(!isdigit(literal[0]))
        {
            value = static_cast<int>(literal[0]);
		std::cout << "int: " << value << std::endl;
        return (value);
        }
		value = std::stoi(literal);
		std::cout << "int: " << value << std::endl;
		return (value);
	}
	catch (const std::exception &)
	{
		std::cout << "int: impossible 4" << std::endl;
	}
	return (0);
}

float ScalarConverter::toFloat(const std::string &literal)
{
	float	value;

	if (!checkNumber(literal, "float"))
		return (0);
	try
	{
         if(!isdigit(literal[0]))
        {
            value = static_cast<float>(literal[0]);
		std::cout << "float: " << value << std::endl;
        return (value);
        }
		value = std::stof(literal);
		std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
		return (value);
	}
	catch (const std::exception &)
	{
		std::cout << "float: impossible" << std::endl;
	}
	return (0.0f);
}

double ScalarConverter::toDouble(const std::string &literal)
{
	double	value;

	if (!checkNumber(literal, "double"))
		return (0);
	try
	{
		value = std::stod(literal);
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
		return (value);
	}
	catch (const std::exception &)
	{
		std::cout << "double: impossible" << std::endl;
	}
	return (0.0);
}
ScalarConverter::ScalarConverter()
{
}
ScalarConverter::~ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &)
{
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
	return (*this);
}
