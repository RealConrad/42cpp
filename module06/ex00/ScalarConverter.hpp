#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <climits>
#include <iomanip>
#include <cmath> // For std::fabs

enum Types {
	DATA_INVALID,
	DATA_VALID,
	DATA_UNRECOGNIZED,
};

class ScalarConverter {
	public:
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static void convert(const std::string& str);
		
	private:
		bool isValid(const std::string& str, double& value);
		Types findDataType(const std::string& str, ScalarConverter& sc, double& value);
		void displayInvalid(const std::string& str);
		void displayValid(double& value);
		// By making the constructor private, you prevent users from creating instances of the ScalarConverter class.
		// This is because users cannot access private members of a class, including constructors.
		ScalarConverter();
};

#endif