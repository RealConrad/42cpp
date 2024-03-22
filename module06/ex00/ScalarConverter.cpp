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

void ScalarConverter::convert(const std::string& str) {
	ScalarConverter sc;
	double value = 0;

	switch(sc.findDataType(str, sc, value)) {
		case DATA_INVALID:
			sc.displayInvalid(str);
			break;
		case DATA_VALID:
			sc.displayValid(value);
			break;
		default:
			std::cout << "The string '" << str << "' is not recorgnized" << std::endl;
			break;
	}
}

Types ScalarConverter::findDataType(const std::string& str, ScalarConverter& sc, double& value) {
	std::istringstream iss(str);

	if (str == "nanf" || str == "nan")
		return DATA_INVALID;
	if (str == "+inff" || str == "+inf")
		return DATA_INVALID;
	if (str == "-inff" || str == "-inf")
		return DATA_INVALID;
	if (sc.isValid(str, value))
		return DATA_VALID;
	return DATA_UNRECOGNIZED;
}

/* --------------------------------- Display -------------------------------- */

void ScalarConverter::displayInvalid(const std::string& str) {
	std::string copy = str; // workaround str being const xd

	std::cout << "Char: Invalid" << std::endl;
	std::cout << "Int: Invalid" << std::endl;
	if (str == "nanf" || str == "-inff" || str == "+inff") {
		std::cout << "Float: " << str << std::endl;
		copy[copy.length()] = '\0';
		std::cout << "Double: " << copy << std::endl;
	} else {
		std::cout << "Float: " << str << "f" << std::endl;
		std::cout << "Double: " << str << std::endl;
	}
}

void ScalarConverter::displayValid(double& value) {
	// Char
	if (value < CHAR_MAX && value > CHAR_MIN && std::isprint(static_cast<char>(value))) {
		std::cout << "Char: " << static_cast<char>(value) << std::endl;
	} else {
		std::cout << "Char: Invalid" << std::endl;
	}

	// integer
	if (value <= INT_MAX && value >= INT_MIN) {
		std::cout << "Int: " << static_cast<int>(value) << std::endl;
	} else {
		std::cout << "Int: Invalid" << std::endl;
	}

	std::cout << "Float: " << std::fixed << static_cast<float>(value) << "f" << std::endl;
	// Double
	std::cout << "Double: " << std::fixed << static_cast<double>(value) << std::endl;
}

/**
 * A literal in programming is a direct value given in code. 
 * For example, 'a' is a character literal, 42 is an integer literal, and 4.2 is a double literal. 
 * This function takes these as strings (e.g., "42") and converts them to their respective types.
 * Why do we use istringstream on an existing string?
	- If you use the string directly, you have to interpret each character, and then calculate the numerical value (and verify its numeric). 
		With std::istringstream, you simply do:
		```
		std::string str = "42";
		std::istringstream iss(str);
		int num;
		iss >> num; // The string "42" is converted to the integer 42
		```
*/

bool ScalarConverter::isValid(const std::string& str, double& value) {
	// check if character
	if (str.length() == 1 && std::isalpha(str[0])) {
		value = static_cast<int>(str[0]);
		return true;
	}

	// check if valid number:
	std::string copy = str;
	if (copy[copy.length() - 1] == 'f' || copy[copy.length() - 1] == 'F')
		copy.erase(copy.length() - 1, 1);
	std::istringstream iss(copy);
	double dValue;
	iss >> dValue;
	if (!iss.fail() && iss.eof()) {
		value = dValue;
		return true;
	}
	return (false);
}
