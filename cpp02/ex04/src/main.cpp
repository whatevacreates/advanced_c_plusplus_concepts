#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>
#include <string>
#include <sstream>

// Function to check if all characters in the string are digits
void checkDigits(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            std::cerr << "Invalid input: " << str << " contains non-digit characters." << std::endl;
            exit(1);
        }
    }
}

// Function to convert a string to an integer using stringstream
int stringToInt(const std::string& str) {
    int number;
    std::stringstream ss(str);
    ss >> number;

    // Check for conversion failure or leftover characters
    if (ss.fail() || !ss.eof()) {
        std::cerr << "Conversion failed: Invalid integer format." << std::endl;
        exit(1);
    }
    return number;
}

int main(void) {
    int min, max, tests;
    std::string min_str, max_str, tests_str;

    // Prompt the user for input values
    std::cout << "Output int range for your tests: " << std::endl;
    
    std::cout << "Min value: " << std::endl;
    std::getline(std::cin, min_str);
    
    std::cout << "Max value: " << std::endl;
    std::getline(std::cin, max_str);
    
    std::cout << "Number of tests to run: " << std::endl;
    std::getline(std::cin, tests_str);

    // Validate that inputs are composed only of digits
    checkDigits(min_str);
    checkDigits(max_str);
    checkDigits(tests_str);

    // Convert the validated strings to integers
    min = stringToInt(min_str);
    max = stringToInt(max_str);
    tests = stringToInt(tests_str);

    // Example output (or run some tests here)
    std::cout << "Min: " << min << ", Max: " << max << ", Tests: " << tests << std::endl;

    return 0;
}
