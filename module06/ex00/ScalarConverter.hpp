#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <climits> // ????
#include <iomanip>

enum Types {
	DATA_NAN,
	DATA_INF_POSITIVE,
	DATA_INF_NEGATIVE,
	DATA_CHAR,
	DATA_INT,
	DATA_DOUBLE,
	DATA_FLOAT,
	DATA_UNRECOGNIZED
};

class ScalarConverter {
	public:
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		// Helper functions
		static bool isFloat(const std::string& str);
		static bool isInt(const std::string& str);
		static bool isDouble(const std::string& str);

		static void displayChar(const std::string& str);
		static void displayInt(const std::string& str);
		static void displayFloat(const std::string& str);
		static void displayDouble(const std::string& str);

		static Types findDataType(const std::string& str);
		static void displayInvalid(const std::string& str);
		static void convert(const std::string& str);
		
	private:
		// By making the constructor private, you prevent users from creating instances of the ScalarConverter class.
		// This is because users cannot access private members of a class, including constructors.
		ScalarConverter();
};

#endif