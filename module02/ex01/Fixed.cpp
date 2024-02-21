#include "Fixed.hpp"

/* ------------------------------ Constructors ------------------------------ */

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(const int num) {
	std::cout << "Default int constructor called" << std::endl;
	this->fixedPoint = num << this->fractionalBits;
}

Fixed::Fixed(const float num) {
	std::cout << "Default float constructor called" << std::endl;
	// (1 << bits) is basically 2^bits. Shifting 1 to the left by `n` in binary is equivalent to 2^n
	this->fixedPoint = static_cast<int>(roundf(num * (1 << this->fractionalBits)));
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

// When using `<< a` compiler will call this function
std::ostream& operator<<(std::ostream &out, const Fixed &num) {
	out << num.toFloat();
	return out;
}

/* ---------------------------- Member functions ---------------------------- */

int Fixed::getRawBits(void) const {
	return this->fixedPoint;
}

void Fixed::setRawBits(int const raw) {
	this->fixedPoint = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->getRawBits()) / static_cast<float>(1 << this->fractionalBits);
}

int Fixed::toInt(void) const {
	return this->fixedPoint >> fractionalBits;
}
