#include <iostream>
#include <string>

int main(void) {
	std::string myString = "HI THIS IS BRAIN";
	std::string* stringPTR = &myString; // use '*' for pointers
	std::string& stringREF = myString; // use '&' for references

	std::cout << "Memory addresses:" << std::endl;
	std::cout << "myString: " << &myString << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value:" << std::endl;
	std::cout << "myString: " << myString << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;

	return (0);
}
