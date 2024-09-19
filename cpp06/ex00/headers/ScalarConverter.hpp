#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib> 
#include <iomanip> 

class ScalarConverter 
{
private:
    
    ScalarConverter();
    ~ScalarConverter();
  
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter& operator=(const ScalarConverter &other);

    static char toChar(const std::string &literal);
    static int toInt(const std::string &literal);   
    static float toFloat(const std::string &literal); 
    static double toDouble(const std::string &literal); 

public:
   
    static void convert(const std::string &literal);
};

#endif
