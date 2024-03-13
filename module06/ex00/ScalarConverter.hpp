#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <climits> // ????
#include <iomanip>

class ScalarConverter {
    public:
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        static void convert(const std::string& str);
    private:
        // By making the constructor private, you prevent users from creating instances of the ScalarConverter class.
        // This is because users cannot access private members of a class, including constructors.
        ScalarConverter();
};

#endif