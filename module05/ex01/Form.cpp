#include "Form.hpp"

Form::Form():
	name("Default contract name"),
	gradeToSign(1),
	gradeToExecute(1),
	isSigned(false)
	{

}

Form::Form(const Form& other):
	name(other.name),
	gradeToSign(other.gradeToSign),
	gradeToExecute(other.gradeToExecute),
	isSigned(other.isSigned) {

}

Form::Form(std::string name, int gradeToSign, int gradeToExecute, bool isSigned):
	name(name),
	gradeToSign(gradeToSign),
	gradeToExecute(gradeToExecute),
	isSigned(isSigned)
{
	if (this->gradeToSign < 1) throw GradeTooLowException();
	if (this->gradeToSign > 150) throw GradeTooHighException();
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->isSigned = other.getIsSigned();
	}
	return *this;
}

Form::~Form() {}

/* ---------------------------- Getter functions ---------------------------- */
std::string Form::getName() const {
	return this->name;
}

bool Form::getIsSigned() const {
	return this->isSigned;
}

int Form::getGradeToSign() const {
	return this->gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b) {
	if (this->isSigned)
		throw AlreadySigned();
	if (b.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << "Form information:" << std::endl;
	out << "Name: " << form.getName() << std::endl;
	out << "Is Signed: " << form.getIsSigned() << std::endl;
	out << "Grade to execute: " << form.getGradeToExecute() << std::endl;
	out << "Grade to sign: " << form.getGradeToSign() << std::endl;
	return out;
}

/* ------------------------------- Exceptions ------------------------------- */
const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Form::AlreadySigned::what() const throw() {
	return "Form already signed";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}
