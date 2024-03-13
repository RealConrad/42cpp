#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include <fstream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		virtual void execute(Bureaucrat const& executor) const;
};

#endif