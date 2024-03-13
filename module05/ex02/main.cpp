#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void testRobotomyRequestForm() {
	std::cout << std::endl;
	std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;
	std::cout << "/*                             RobotomyRequestForm                            */" << std::endl;
	std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;
	std::cout << std::endl;

	Bureaucrat engineer("Engineer", 1);
	RobotomyRequestForm robotForm("Bob");

	try {
		robotForm.beSigned(engineer);
		robotForm.execute(engineer);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	Bureaucrat intern("Intern", 150);
	try {
		robotForm.execute(intern);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testPresidentialPardonForm() {
	std::cout << std::endl;
	std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;
	std::cout << "/*                           PresidentialPardonForm                           */" << std::endl;
	std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;
	std::cout << std::endl;
	Bureaucrat president("President", 1);
	PresidentialPardonForm pardonForm("Criminal");
	pardonForm.beSigned(president);

	try {
		pardonForm.execute(president);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat vicePresident("VicePresident", 20);
	try {
		pardonForm.execute(vicePresident);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void testShrubberyCreationForm() {
	std::cout << std::endl;
	std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;
	std::cout << "/*                            ShrubberyCreationForm                           */" << std::endl;
	std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;
	std::cout << std::endl;

	Bureaucrat boss("Boss", 1);
	ShrubberyCreationForm form("home");

	try {
		form.beSigned(boss);
		form.execute(boss);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat lowRank("lowRank", 150);
	try { 
		form.execute(lowRank);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
void testBureaucrat() {
	std::cout << std::endl;
	std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;
	std::cout << "/*                                 Bureaucrat                                 */" << std::endl;
	std::cout << "/* -------------------------------------------------------------------------- */" << std::endl;
	std::cout << std::endl;

	Bureaucrat john("john", 50);
	std::cout << john << std::endl;
	std::cout << "Testing grade increment/decrement:" << std::endl;
	john.decrement();
	std::cout << john << std::endl;
	john.increment();
	std::cout << john << std::endl;

	std::cout << "Testing invalid grades" << std::endl;
	try {
		Bureaucrat invalidGrade("InvalidGrade", 0);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	testBureaucrat();
	testShrubberyCreationForm();
	testRobotomyRequestForm();
	testPresidentialPardonForm();
}