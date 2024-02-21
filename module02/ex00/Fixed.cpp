#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const Fixed &copy) { // use reference to avoid unnessary copies during call
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(copy.getRawBits());
}

Fixed& Fixed::operator=(const Fixed &num) {
	std::cout << "Copy operator called" << std::endl;
	this->fixedPoint = num.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "Raw bits funciton called" << std::endl;
	return this->fixedPoint;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "Setting raw bits" << std::endl;
	this->fixedPoint = raw;
}
