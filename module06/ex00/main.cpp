#include "ScalarConverter.hpp"

void testChars() {
	std::cout << "==============================" << std::endl;
	std::cout << "CHARS" << std::endl;
	std::cout << "==============================" << std::endl;
	std::cout << std::endl;

	ScalarConverter::convert("a");
	std::cout << std::endl;
	ScalarConverter::convert("z");
	std::cout << std::endl;
	ScalarConverter::convert("A");
	std::cout << std::endl;
	ScalarConverter::convert("AA");
	std::cout << std::endl;
	ScalarConverter::convert("This is not a char");
	std::cout << std::endl;
	ScalarConverter::convert("48");
	std::cout << std::endl;
}

void testInts() {
	std::cout << "==============================" << std::endl;
	std::cout << "Ints" << std::endl;
	std::cout << "==============================" << std::endl;
	std::cout << std::endl;

	ScalarConverter::convert("48");
	std::cout << std::endl;
	ScalarConverter::convert("1");
	std::cout << std::endl;
	ScalarConverter::convert("-42");
	std::cout << std::endl;
	ScalarConverter::convert("-2147483648");
	std::cout << std::endl;
	ScalarConverter::convert("-2147483647");
	std::cout << std::endl;
	ScalarConverter::convert("2147483648");
	std::cout << std::endl;
}

void testFloats() {
	std::cout << "==============================" << std::endl;
	std::cout << "Floats" << std::endl;
	std::cout << "==============================" << std::endl;
	std::cout << std::endl;

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
	std::cout << std::endl;
	std::cout << "Nothing yet" << std::endl;
}

int main() {
	testChars();
	testInts();
	testFloats();
	testDouble();
}
