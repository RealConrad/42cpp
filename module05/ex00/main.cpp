#include "Bureaucrat.hpp"

int main() {
	std::cout << "===== TEST 1 =====" << std::endl;
	try {
		Bureaucrat john("John Doe", 2);
		std::cout << john << std::endl;
		john.increment();
		std::cout << john << std::endl;
		john.decrement();
		john.decrement();
		std::cout << john << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== TEST 2 =====" << std::endl;
	try {
		Bureaucrat john("John Doe", 1);
		std::cout << john << std::endl;
		john.decrement();
		std::cout << john << std::endl;
		john.decrement();
		std::cout << john << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== TEST 3 =====" << std::endl;
	try {
		Bureaucrat john("John Doe", 149);
		std::cout << john << std::endl;
		john.increment();
		std::cout << john << std::endl;
		john.increment();
		std::cout << john << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
