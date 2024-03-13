#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {
	Intern intern;

	try {
		AForm* form1 = intern.makeForm("presidential request", "Conrad");
		std::cout << "Created presidential request form!" << std::endl;
		delete form1;
	} catch (std::exception& e) {
		std::cout << "Failed to create form: " << e.what() << std::endl;
	}

	try {
		AForm* form2 = intern.makeForm("robotomy request", "Conrad");
		std::cout << "Created robotomy request form!" << std::endl;
		delete form2;
	} catch (std::exception& e) {
		std::cout << "Failed to create form: " << e.what() << std::endl;
	}

	try {
		AForm* form3 = intern.makeForm("shrubbery request", "Conrad");
		std::cout << "Created shrubbery request form!" << std::endl;
		delete form3;
	} catch (std::exception& e) {
		std::cout << "Failed to create form: " << e.what() << std::endl;
	}

	try {
		AForm* form4 = intern.makeForm("invalid request", "Conrad");
		std::cout << "Created invalid request form!" << std::endl;
		delete form4;
	} catch (std::exception& e) {
		std::cout << "Failed to create form: " << e.what() << std::endl;
	}
}
