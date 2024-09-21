

#include "ScalarConverter.hpp"
#include "Utils.hpp"

void ScalarConverter::convert(const std::string &literal)
{
	toChar(literal);
	toInt(literal);
	toFloat(literal);
	toDouble(literal);
}

void ScalarConverter::toChar(const std::string &literal)
{
	int	value;

	if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
	{
		std::cout << BOLD << PASTEL_LAVENDER << "CHAR: " << RESET << literal[0] << std::endl;
		return ;
	}
	else
	{
		value = std::strtol(literal.c_str(), NULL, 10);
		if (value >= 0 && value <= 127 && isprint(static_cast<char>(value)))
		{
			std::cout << BOLD << PASTEL_LAVENDER << "CHAR: '" << RESET << static_cast<char>(value) << "'" << std::endl;
			return ;
		}
	}
	std::cout << BOLD << PASTEL_LAVENDER << "CHAR: " << RESET << "not displayable" << RESET << std::endl;
}

void ScalarConverter::toInt(const std::string &literal)
{
	int	value;

	try
	{
		if (!isdigit(literal[0]) && literal[0] != '-')
			value = static_cast<int>(literal[0]);
		else
			value = std::stoi(literal);
		std::cout << BOLD << PASTEL_LAVENDER << "INT: " << RESET << value << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << BOLD << PASTEL_LAVENDER << "INT: " << RESET << "not displayable. error: " << e.what() << std::endl;
	}
}

void ScalarConverter::checkPrecision(const std::string literal, int &precision)
{
	size_t	i;
	size_t	zeros;
	size_t	k;

	zeros = 0;
	k = literal.length() - 1;
	i = 0;
	while (i < literal.length() && literal[i] != '.')
		i++;
	while (k > i && (literal[k] == '0' || literal[k] == 'f'))
	{
		k--;
		if (literal[k] == 'f')
			zeros--;
		zeros++;
	}
	while (i < literal.length() && literal[i] != 'f')
	{
		precision++;
		i++;
	}
	if (precision != 0)
	{
		precision -= 1;
		if (zeros > 0)
			precision -= zeros;
	}
	if (precision == 0)
		precision = 1;
}

void ScalarConverter::toFloat(const std::string &literal)
{
	float	value;
	int		precision;

	precision = 0;
	try
	{
		if (!isdigit(literal[0]) && literal[0] != '-')
		{
			checkPrecision(literal, precision);
			value = static_cast<float>(literal[0]);
			std::cout << BOLD << PASTEL_LAVENDER << "FLOAT: " << RESET << std::fixed << std::setprecision(precision) << value << 'f' << std::endl;
			return ;
		}
		else
			value = std::stof(literal);
		checkPrecision(literal, precision);
		if (precision > 7)
			precision = 7;
		std::cout << BOLD << PASTEL_LAVENDER << "FLOAT: " << RESET << std::fixed << std::setprecision(precision) << value << 'f' << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << BOLD << PASTEL_LAVENDER << "FLOAT: " << RESET << "impossible. error: " << e.what() << std::endl;
	}
}
void ScalarConverter::toDouble(const std::string &literal)
{
	double	value;
	float	floatValue;
	int		precision;

	precision = 0;
	try
	{
		if (literal.find('f') != std::string::npos && literal.length() > 1)
		{
			floatValue = std::stof(literal);
			value = static_cast<double>(floatValue);
		}
		else if (!isdigit(literal[0]) && literal[0] != '-')
		{
			checkPrecision(literal, precision);
			value = static_cast<double>(literal[0]);
			std::cout << BOLD << PASTEL_LAVENDER << "DOUBLE: " << std::setprecision(precision) << RESET << value << std::endl;
			return ;
		}
		else
			value = std::stod(literal);
		checkPrecision(literal, precision);
		std::cout << BOLD << PASTEL_LAVENDER << "DOUBLE: " << RESET << std::setprecision(precision) << value << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << BOLD << PASTEL_LAVENDER << "DOUBLE: " << RESET << "impossible. error: " << e.what() << std::endl;
	}
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
