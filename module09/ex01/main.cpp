#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: Invalid parameters" << std::endl;
		std::cout << "Usage: ./RPN \"<parameters>\"" << std::endl;
		return 1;
	}
	RPN calculator;
	try {
		calculator.executeExpression(argv[1]);
	}
	catch (std::exception& e ) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
