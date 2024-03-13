#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	private:
		AForm* createPresidentialPardonForm(const std::string& target);
		AForm* createRobotomyReqeustForm(const std::string& target);
		AForm* createShrubberyCreationForm(const std::string& target);
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
		AForm* makeForm(const std::string& formName, const std::string& target);

		class InvalidFormException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

typedef AForm* (Intern::*InternFormCreation)(const std::string& target);

#endif