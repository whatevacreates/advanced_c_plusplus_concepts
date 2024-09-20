

#include "ScalarConverter.hpp"


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
		std::cout << "char: '" << literal[0] << "'" << std::endl;
		return;
	}
	else
	{
        if (literal.length() != 1 && !checkNumber(literal, "char"))
		return;
		value = std::strtol(literal.c_str(), NULL, 10);
		if (value >= 0 && value <= 127 && isprint(static_cast<char>(value)))
		{
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
return;
		}
	}
	std::cout << "char: impossible" << std::endl;
}
bool ScalarConverter::checkNumber(const std::string &literal, const std::string &scalar_type)
{
	size_t	i;
    int dot_count = 0;
if(literal.length() == 1 && literal[0] >= 9 && literal[0] <= 13)
return true;
	if (literal.empty())
	{
		std::cout << scalar_type << ": impossible" << std::endl;
		return (false);
	}
	i = 0;
	if (!isdigit(literal[i]) && isprint(literal[i]))
	{
		if ((literal.size() == 1 && literal[i] == '-')|| (literal.length() > 1 && literal[i] != '-'))
		{ 
			std::cout << scalar_type << ": impossible" << std::endl;
			return (false);
		}
		i++; 
	}
	
	for (; i < literal.length(); ++i)
	{
        if(literal[i] == 'f' && !literal[i + 1] && literal.length() > 1)
        return true;
        if(literal[i] == '.')
        dot_count++;
		if (((!std::isdigit(literal[i]) && literal[i] != '.') ||  (literal[i] == '.' && !std::isdigit(literal[i+1])) || (dot_count > 1)))
		{
			std::cout << scalar_type << ": impossible" << std::endl;
			return (false);
		}
	}
	return (true);
}
void ScalarConverter::toInt(const std::string &literal)
{
	int	value;

	if (!checkNumber(literal, "int"))
		return;

	try
	{
		
        
        if(!isdigit(literal[0]) && literal[0] != '-')
      
            value = static_cast<int>(literal[0]);
	else
		value = std::stoi(literal);
		std::cout << "int: " << value << std::endl;
		
	}
	catch (const std::exception &)
	{
		std::cout << "int: impossible" << std::endl;
	}
}

void ScalarConverter::toFloat(const std::string &literal)
{
	float	value;
   
	if (!checkNumber(literal, "float"))
		return;
	try
	{
    
         if(!isdigit(literal[0]) && literal[0] != '-') 
		 {
			
			 value = static_cast<float>(literal[0]);
		 }
           
		else
        value = std::stof(literal);
       if(literal.find('.') != std::string::npos)
		std::cout << "float: " << std::setprecision(7) << value << 'f'<< std::endl;
        else
        std::cout << "float: " << std::setprecision(7) << value << ".0f"<< std::endl;
	}
	catch (const std::exception &)
	{
		std::cout << "float: impossible" << std::endl;
	}
	
	
}
void ScalarConverter::toDouble(const std::string &literal)
{
    double value;

    if (!checkNumber(literal, "double"))  
        return;

    try
    {
     if(literal.find('f') != std::string::npos && literal.length() > 1)
     {
		std::cout << " are we here 1" <<std::endl;
        float floatValue = std::stof(literal);
        value = static_cast<double>(floatValue); 
     }
	  else if (!isdigit(literal[0]) && literal[0] != '-') 
		 {

			 value = static_cast<double>(literal[0]);
		 }
     
     else
	 {
        value = std::stod(literal);	
		
		}
        if(literal.find('.') != std::string::npos)
        std::cout << "double: " << std::setprecision(std::numeric_limits<double>::max_digits10) << value << std::endl;
        else
         std::cout << "double: " << std::setprecision(std::numeric_limits<double>::max_digits10) << value << ".0" << std::endl;
    }
    catch (const std::exception &)
	{
		std::cout << "double: impossible" << std::endl;
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
