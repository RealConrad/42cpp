#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name;
		const int gradeToSign;
		const int gradeToExecute;
		bool isSigned;
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute, bool isSigned);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		// Getter functions
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& b);

		// Custom exceptions
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class AlreadySigned: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form& b);

#endif