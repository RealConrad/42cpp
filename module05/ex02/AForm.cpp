#include "AForm.hpp"

AForm::AForm():
	name("Default contract name"),
	gradeToSign(1),
	gradeToExecute(1),
	isSigned(false)
	{

}

AForm::AForm(const AForm& other):
	name(other.name),
	gradeToSign(other.gradeToSign),
	gradeToExecute(other.gradeToExecute),
	isSigned(other.isSigned) {

}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute, bool isSigned):
	name(name),
	gradeToSign(gradeToSign),
	gradeToExecute(gradeToExecute),
	isSigned(isSigned)
{
	if (this->gradeToSign < 1) throw GradeTooHighException();
	if (this->gradeToSign > 150) throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->isSigned = other.getIsSigned();
	}
	return *this;
}

AForm::~AForm() {}

/* ---------------------------- Getter functions ---------------------------- */
std::string AForm::getName() const {
	return this->name;
}

bool AForm::getIsSigned() const {
	return this->isSigned;
}

int AForm::getGradeToSign() const {
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (this->isSigned)
		throw AlreadySigned();
	if (b.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
	out << "Form information:" << std::endl;
	out << "Name: " << form.getName() << std::endl;
	out << "Is Signed: " << form.getIsSigned() << std::endl;
	out << "Grade to execute: " << form.getGradeToExecute() << std::endl;
	out << "Grade to sign: " << form.getGradeToSign() << std::endl;
	return out;
}

/* ------------------------------- Exceptions ------------------------------- */
const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* AForm::AlreadySigned::what() const throw() {
	return "Form already signed";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char* AForm::NotSignedException::what() const throw() {
	return "Form not signed";
}
