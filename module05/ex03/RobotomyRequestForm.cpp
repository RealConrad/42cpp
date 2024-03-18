#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45, false), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45, false), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!this->isSigned) throw NotSignedException();
	if (this->gradeToExecute < executor.getGrade()) throw GradeTooLowException();

	std::cout << "* Drilling noises * " << std::endl;
	// seed/initialize the RNG, basically give it a random starting point.
	// Use time to ensure that it will be different everytime the program runs
	srand(time(0));
	if (rand() % 2) { // 50% chance
		std::cout << this->target << " has been robotomized" << std::endl;
	} else {
		std::cout << this->target << " failed to be robotomized" << std::endl;
	}
}
