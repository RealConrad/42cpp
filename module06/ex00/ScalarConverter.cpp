#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

/**
 * @brief A literal in programming is a direct value given in code. 
 * For example, 'a' is a character literal, 42 is an integer literal, and 4.2 is a double literal. 
 * This function takes these as strings (e.g., "42") and converts them to their respective types.
 * @param str The string to check
 * @note Why do we use istringstream on an existing string?
        - If you use the string directly, you have to interpret each character, and then calculate the numerical value (and verify its numeric). 
          With std::istringstream, you simply do:
          ```
            std::string str = "42";
            std::istringstream iss(str);
            int num;
            iss >> num; // The string "42" is converted to the integer 42
          ```
*/ 
void ScalarConverter::convert(const std::string& str) {
    std::cout << std::endl;
    std::istringstream iss(str);
    
    // Check if char literal - it will be in the form 'a', 'b'...
    if (str[str.length() - 1] == '\'' && str[0] == '\'' && str.length() == 3) {
        char value = str[1];
        std::cout << "Char: " << value << std::endl;
    } else { // Handle non char literals
        double value;
        iss >> value; // convert the string to double
        if (iss.fail()) {
            std::cout << std::endl;
            // Handle pseduo stuff???
        } else {
            std::cout << "Char:  conversion not possible" << std::endl;
            // Check if int and if conversion possible
            if (value >= INT_MIN && value <= INT_MAX)
                std::cout << "Int: " << static_cast<int>(value) << std::endl;
            else
                std::cout << "Int: conversion not possible due to overflow" << std::endl;

            std::cout << "Float: " << static_cast<float>(value) << "f" << std::endl;
            std::cout << "Double: " << static_cast<double>(value) << std::endl;
        }
    }
}

