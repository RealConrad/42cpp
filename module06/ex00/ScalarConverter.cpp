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
	switch(ScalarConverter::findDataType(str)) {
		case DATA_NAN:
		case DATA_INF_POSITIVE:
		case DATA_INF_NEGATIVE:
			ScalarConverter::displayInvalid(str);
			break;
		case DATA_CHAR:
			ScalarConverter::displayChar(str);
			break;
		case DATA_INT:
			ScalarConverter::displayInt(str);
			break;
		case DATA_FLOAT:
			ScalarConverter::displayFloat(str);
			break;
		case DATA_DOUBLE:
			ScalarConverter::displayDouble(str);
			break;
		default:
			std::cout << "The string '" << str << "' is not recorgnized" << std::endl;
			break;
	}
}

Types ScalarConverter::findDataType(const std::string& str) {
	std::istringstream iss(str);

	if (str == "nanf" || str == "nan")
		return DATA_NAN;
	else if (str == "+inff" || str == "+inf")
		return DATA_INF_POSITIVE;
	else if (str == "-inff" || str == "-inf")
		return DATA_INF_NEGATIVE;
	else if (str.length() == 1 && std::isalpha(str[0]))
		return DATA_CHAR;
	else if (ScalarConverter::isInt(str)) {
		return DATA_INT;
	} else if (ScalarConverter::isFloat(str)) {
		return DATA_FLOAT;
	} else if (ScalarConverter::isDouble(str)) {
		return DATA_DOUBLE;
	}
	return DATA_UNRECOGNIZED;
}

/* --------------------------------- Display -------------------------------- */

void ScalarConverter::displayInvalid(const std::string& str) {
	std::string copy = str; // workaround str being const xd

	std::cout << "Char: Invalid" << std::endl;
	std::cout << "Int: Invalid" << std::endl;
	std::cout << "Float: " << str << "f" << std::endl;
	if (str == "nanf") {
		copy.back() = '\0';
		std::cout << "Double: " << copy << std::endl;
	} else {
		std::cout << "Double: " << str << std::endl;
	}
}

void ScalarConverter::displayChar(const std::string& str) {
	std::cout << "Char: " << str[0] << std::endl;
	std::cout << "Int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "Float: " << static_cast<float>(str[0]) << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(str[0]) << std::endl;
}

/**
 * A literal in programming is a direct value given in code. 
 * For example, 'a' is a character literal, 42 is an integer literal, and 4.2 is a double literal. 
 * This function takes these as strings (e.g., "42") and converts them to their respective types.
 * note Why do we use istringstream on an existing string?
	- If you use the string directly, you have to interpret each character, and then calculate the numerical value (and verify its numeric). 
		With std::istringstream, you simply do:
		```
		std::string str = "42";
		std::istringstream iss(str);
		int num;
		iss >> num; // The string "42" is converted to the integer 42
		```
*/ 
void ScalarConverter::displayInt(const std::string& str) {
	std::istringstream iss(str);
	int iValue;
	char c;

	// parse string to int
	iss >> iValue;
	if (!iss.fail() && iss.eof()) {
		c = static_cast<char>(iValue);
		if (std::isprint(c))
			std::cout << "Char: " << c << std::endl;
		else
			std::cout << "Char: Invalid" << std::endl;
		std::cout << "Int: " << iValue << std::endl;
		std::cout << "Float: " << static_cast<float>(iValue) << "f" << std::endl;
		std::cout << "Doube: " << static_cast<double>(iValue) << std::endl;
	}
}

void ScalarConverter::displayFloat(const std::string& str) {
	std::string temp = str;
	if (temp.back() == 'f' || temp.back() == 'F')
		temp.pop_back();
	std::istringstream iss(temp);
	float fValue;

	// parse string to float
	iss >> fValue;
	if (!iss.fail() && iss.eof()) {
		std::cout << "FLOAT TYPE!" << std::endl;
		// Display as char
		if (std::isprint(static_cast<char>(fValue)))
			std::cout << "Char: " << static_cast<char>(fValue) << std::endl;
		else
			std::cout << "Char: Invalid" << std::endl;

		// Display as int
		if (fValue > INT_MAX || fValue < INT_MIN) {
			std::cout << "Int: Invalid" << std::endl;
		} else {
			std::cout << "Int: " << static_cast<int>(fValue) << std::endl;
		}

		std::cout << "Float: " << fValue << "f" << std::endl;
		std::cout << "Double: " << static_cast<double>(fValue) << std::endl;
	}
}

void ScalarConverter::displayDouble(const std::string& str) {
	std::istringstream iss(str);
	double dValue;
	// parse string to double
	iss >> dValue;
	if (!iss.fail() && iss.eof()) {
		std::cout << "DOUBLE TYPE!" << std::endl;
		// Display as char
		if (std::isprint(static_cast<char>(dValue)))
			std::cout << "Char: " << static_cast<char>(dValue) << std::endl;
		else
			std::cout << "Char: Invalid" << std::endl;

		// Display as int
		if (dValue > INT_MAX || dValue < INT_MIN) {
			std::cout << "Int: Invalid" << std::endl;
		} else {
			std::cout << "Int: " << static_cast<int>(dValue) << std::endl;
		}
		std::cout << "Float: " << dValue << "f" << std::endl;
		std::cout << "Double: " << static_cast<double>(dValue) << std::endl;
	}
}

/* ----------------------------- Check data type ---------------------------- */

bool ScalarConverter::isInt(const std::string& str) {
	std::istringstream iss(str);
	int iValue;
	iss >> iValue;
	if (!iss.fail() && iss.eof() && iValue < INT_MAX && iValue > INT_MIN)
	{
		return true;
	}
	return false;
}

bool ScalarConverter::isFloat(const std::string& str) {
	std::string temp = str;

	if (temp.back() == 'f' || temp.back() == 'F')
		temp.pop_back();
	if (temp.find('.') != std::string::npos) {
		std::istringstream iss(temp);
		float fValue;
		iss >> fValue;
		if (!iss.fail() && iss.eof())
			return true;
	}
	return false;
}

bool ScalarConverter::isDouble(const std::string& str) {
	if (!ScalarConverter::isInt(str) && !ScalarConverter::isFloat(str)) {
		std::istringstream iss(str);
		double dValue;
		iss >> dValue;
		if (!iss.fail() && iss.eof())
			return true;
	}
	return (false);
}
