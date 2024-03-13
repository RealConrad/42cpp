#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}
AForm* Intern::createRobotomyReqeustForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}
AForm* Intern::createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

const char* Intern::InvalidFormException::what() const throw() {
	return "Invalid form type";
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	static const InternFormCreation formCreationFunctions[] = {
		&Intern::createPresidentialPardonForm,
		&Intern::createRobotomyReqeustForm,
		&Intern::createShrubberyCreationForm
	};
	static const std::string formNames[] = {"presidential request", "robotomy request", "shrubbery request"};

	for (int i = 0; i < 3; i++) {
		if (formNames[i] == formName) {
			return (this->*formCreationFunctions[i])(target);
		}
	}
	throw InvalidFormException();
}
