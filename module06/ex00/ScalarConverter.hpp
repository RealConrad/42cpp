#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <climits>
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

		static void convert(const std::string& str);
		
	private:
		bool isFloat(const std::string& str);
		bool isInt(const std::string& str);
		bool isDouble(const std::string& str);

		void displayChar(const std::string& str);
		void displayInt(const std::string& str);
		void displayFloat(const std::string& str);
		void displayDouble(const std::string& str);

		Types findDataType(const std::string& str, ScalarConverter& sc);
		void displayInvalid(const std::string& str);
		// By making the constructor private, you prevent users from creating instances of the ScalarConverter class.
		// This is because users cannot access private members of a class, including constructors.
		ScalarConverter();
};

#endif