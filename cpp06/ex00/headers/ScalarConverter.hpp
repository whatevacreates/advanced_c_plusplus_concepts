#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>
# include <climits>

class ScalarConverter
{
  private:
	ScalarConverter();
	~ScalarConverter();

	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);

	static void toChar(const std::string &literal);
	static void toInt(const std::string &literal);
	static void toFloat(const std::string &literal);
	static void toDouble(const std::string &literal);
    static void checkPrecision(const std::string literal, int &precision);

  public:
	static void convert(const std::string &literal);
};

#endif
