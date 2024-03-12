#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "=====Test 1=====" << std::endl;
	try {
		Bureaucrat john1("John Doe", 50);
		Form form("Contract 1", 100, 100, false);
		john1.signForm(form);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=====Test 2=====" << std::endl;
	try {
		Bureaucrat john2("John Doe", 66);
		Form form("Contract 2", 50, 100, false);
		john2.signForm(form);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=====Test 3=====" << std::endl;
	try {
		Bureaucrat john3("John Doe", 60);
		Form form("Contract 3", 100, 50, false);
		john3.signForm(form);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=====Test 4=====" << std::endl;
	try {
		Bureaucrat john4("John Doe", 60);
		Form form("Contract 4", 151, 50, false);
		john4.signForm(form);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=====Test 5=====" << std::endl;
	try {
		Bureaucrat john5("John Doe", 50);
		Form form("Contract 5", 100, 100, true);
		john5.signForm(form);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=====Test 6=====" << std::endl;
	try {
		Bureaucrat john6("John Doe", 50);
		Form form("Contract 6", 100, 100, false);
		form.beSigned(john6);
		std::cout << form;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
