#include "Span.hpp"

void testSubjectExample();
void testValid();
void testInvalid();

int main() {
	testSubjectExample();
	testValid();
	testInvalid();
	return 0;
}

void testSubjectExample() {
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

}

void testValid() {
	std::cout << "=============TESTING VALID=============" << std::endl;
	try {
		std::cout << "===TEST 1===" << std::endl;
		Span sp(20);

		sp.addMultiple(20);
		sp.display();
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "===TEST 2===" << std::endl;
		Span sp(7);

		sp.addNumber(0);
		sp.addNumber(10);
		sp.addNumber(10);
		sp.addNumber(50);
		sp.addNumber(120);
		sp.addNumber(-20);
		sp.addNumber(1230);
		sp.display();
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "===TEST 3===" << std::endl;
		Span sp(10000);

		sp.addMultiple(10000);
		sp.display();
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testInvalid() {
	std::cout << "\n=============TESTING INVALID=============" << std::endl;
	try {
		std::cout << "===TEST 1===" << std::endl;
		Span sp(1);

		sp.display();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "===TEST 2===" << std::endl;
		Span sp(1);

		std::cout << sp.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "===TEST 3===" << std::endl;
		Span sp(1);

		sp.addNumber(20);
		sp.addNumber(25);
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
