#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Bobby"), grade(1) {
	// std::cout << "Default constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade): name(name) {
	if (grade < 1) throw GradeTooHighException();
	if (grade > 150) throw GradeTooLowException();
	this->grade = grade;
	// std::cout << "Parameterized constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade){
	// std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		grade = other.getGrade();
		// name = other.getName();
	}
	// std::cout << "Copy assignment called" << std::endl;
	return *this;
}


Bureaucrat::~Bureaucrat() {
	// std::cout << "Deconstructor called!" << std::endl;
}

std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::decrement() {
	if (this->grade <= 1) {
		throw GradeTooHighException();
	}
	this->grade--;
}

void Bureaucrat::increment() {
	if (this->grade >= 150) {
		throw GradeTooLowException();
	}
	this->grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	out << "Name: " << b.getName() << ", Grade: " << b.getGrade() << std::endl;
	return out;
}

/* ------------------------------- Exceptions ------------------------------- */
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}
