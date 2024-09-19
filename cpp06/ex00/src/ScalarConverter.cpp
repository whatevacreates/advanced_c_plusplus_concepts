

#include "ScalarConverter.hpp"


// Implementation of the convert method
void ScalarConverter::convert(const std::string &literal) {
    // Check if the literal can be converted to each type and call respective function
    try {
        // Try to convert to each type and print results
        toChar(literal);
        toInt(literal);
        toFloat(literal);
        toDouble(literal);
    }
    catch (const std::exception &e) {
        std::cerr << "Conversion error: " << e.what() << std::endl;
    }
}

// Implementation of conversion functions
char ScalarConverter::toChar(const std::string &literal) {
    // Check if the literal can be converted to char
    if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0])) {
        std::cout << "char: '" << literal[0] << "'" << std::endl;
        return literal[0];
    } else {
        int value = std::strtol(literal.c_str(), NULL, 10);
        if (value >= 0 && value <= 127 && isprint(static_cast<char>(value))) {
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
            return static_cast<char>(value);
        }
    }
    std::cout << "char: impossible" << std::endl;
    return 0;
}

int ScalarConverter::toInt(const std::string &literal) {
    // Try to convert the string to an integer
    try {
        int value = std::stoi(literal);
        std::cout << "int: " << value << std::endl;
        return value;
    } catch (const std::exception &) {
        std::cout << "int: impossible" << std::endl;
    }
    return 0;
}

float ScalarConverter::toFloat(const std::string &literal) {
    // Try to convert the string to a float
    try {
        float value = std::stof(literal);
        std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
        return value;
    } catch (const std::exception &) {
        std::cout << "float: impossible" << std::endl;
    }
    return 0.0f;
}

double ScalarConverter::toDouble(const std::string &literal) {
    // Try to convert the string to a double
    try {
        double value = std::stod(literal);
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
        return value;
    } catch (const std::exception &) {
        std::cout << "double: impossible" << std::endl;
    }
    return 0.0;
}

// Private constructor, destructor, and copy constructor to prevent instantiation
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &) { return *this; }
