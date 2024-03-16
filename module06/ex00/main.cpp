#include "ScalarConverter.hpp"

void testChars();
void testInts();
void testFloats();
void testDouble();
void testInvalid();

int main() {
	// ScalarConverter* sc = new ScalarConverter(); // throws error as its not instanciable
	testChars();
	testInts();
	testFloats();
	testDouble();
	testInvalid();
}



/* -------------------------------------------------------------------------- */
/*                               Test functions                               */
/* -------------------------------------------------------------------------- */
void testChars() {
	std::cout << "==============================" << std::endl;
	std::cout << "CHARS" << std::endl;
	std::cout << "==============================" << std::endl;

	ScalarConverter::convert("a");
	std::cout << std::endl;
	ScalarConverter::convert("z");
	std::cout << std::endl;
	ScalarConverter::convert("Z");
	std::cout << std::endl;
	ScalarConverter::convert("48");
	std::cout << std::endl;
}

void testInts() {
	std::cout << "==============================" << std::endl;
	std::cout << "Ints" << std::endl;
	std::cout << "==============================" << std::endl;

	ScalarConverter::convert("48");
	std::cout << std::endl;
	ScalarConverter::convert("1");
	std::cout << std::endl;
	ScalarConverter::convert("-42");
	std::cout << std::endl;
	ScalarConverter::convert("-2147483648"); // too small for int
	std::cout << std::endl;
	ScalarConverter::convert("-2147483647"); // int min
	std::cout << std::endl;
	ScalarConverter::convert("2147483647"); // int max
	std::cout << std::endl;
	ScalarConverter::convert("2147483648"); // int max
	std::cout << std::endl;
	ScalarConverter::convert("-101");
	std::cout << std::endl;
}

void testFloats() {
	std::cout << "==============================" << std::endl;
	std::cout << "Floats" << std::endl;
	std::cout << "==============================" << std::endl;

	ScalarConverter::convert("10f");
	std::cout << std::endl;
	ScalarConverter::convert("10.0f");
	std::cout << std::endl;
	ScalarConverter::convert("10.12412f");
	std::cout << std::endl;
	ScalarConverter::convert("-10.12412f");
	std::cout << std::endl;
	ScalarConverter::convert("2147483649f");
	std::cout << std::endl;
	ScalarConverter::convert("-2147483649.12f");
	std::cout << std::endl;
}

void testDouble() {
	std::cout << "==============================" << std::endl;
	std::cout << "Double" << std::endl;
	std::cout << "==============================" << std::endl;
	ScalarConverter::convert("123456789435");
	std::cout << std::endl;
	ScalarConverter::convert("-237589353345");
	std::cout << std::endl;
	ScalarConverter::convert("0.0");
	std::cout << std::endl;
	ScalarConverter::convert("");
	std::cout << std::endl;
	ScalarConverter::convert("1.437858");
	std::cout << std::endl;
	ScalarConverter::convert("0.4444444444");
	std::cout << std::endl;
	ScalarConverter::convert("0.88888888");
	std::cout << std::endl;
	
}

void testInvalid() {
	std::cout << "==============================" << std::endl;
	std::cout << "Invalid" << std::endl;
	std::cout << "==============================" << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("AA");
	std::cout << std::endl;
	ScalarConverter::convert("This is not a char");
	std::cout << std::endl;
}
