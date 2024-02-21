#include "Fixed.hpp"

/* ------------------------------ Constructors ------------------------------ */

Fixed::Fixed(void) {
	this->fixedPoint = 0;
}

Fixed::Fixed(const int num) {
	this->fixedPoint = num << this->fractionalBits;
}

Fixed::Fixed(const float num) {
	// (1 << bits) is basically 2^bits. Shifting 1 to the left by `n` in binary is equivalent to 2^n
	this->fixedPoint = static_cast<int>(roundf(num * (1 << this->fractionalBits)));
}

Fixed::~Fixed(void) {
	
}


Fixed::Fixed(const Fixed &copy) { // use reference to avoid unnessary copies during call
	this->setRawBits(copy.getRawBits());
}

/* -------------------------------------------------------------------------- */
/*                              Operator overload                             */
/* -------------------------------------------------------------------------- */

/* ------------------------------- Comparision ------------------------------ */
bool Fixed::operator>(const Fixed &num) const {
	return this->getRawBits() > num.getRawBits() ? true : false;
}

bool Fixed::operator<(const Fixed &num) const {
	return this->getRawBits() < num.getRawBits() ? true : false; 
}

bool Fixed::operator<=(const Fixed &num) const {
	return this->getRawBits() <= num.getRawBits() ? true : false;
}

bool Fixed::operator>=(const Fixed &num) const {
	return this->getRawBits() >= num.getRawBits() ? true : false;
}

bool Fixed::operator!=(const Fixed &num) const {
	return this->getRawBits() != num.getRawBits() ? true : false;
}

bool Fixed::operator==(const Fixed &num) const {
	return this->getRawBits() == num.getRawBits() ? true : false;
}

/* ------------------------------- Arthimetic ------------------------------- */
Fixed Fixed::operator+(const Fixed &num) const {
	return this->toFloat() + num.toFloat();
}

Fixed Fixed::operator-(const Fixed &num) const {
	return this->toFloat() - num.toFloat();
}

Fixed Fixed::operator*(const Fixed &num) const {
	return this->toFloat() * num.toFloat();
}

Fixed Fixed::operator/(const Fixed &num) const {
	if (num.toFloat() == 0) {
		std::cout << "Can't divide by 0. Value will be set to 0" << std::endl;
		return 0;
	}
	return this->toFloat() / num.toFloat();
}

Fixed& Fixed::operator=(const Fixed &num) {
	std::cout << "Copy operator called" << std::endl;
	this->fixedPoint = num.getRawBits();
	return (*this);
}

// When using `<< Fixed a`, the compiler will call this function
std::ostream& operator<<(std::ostream &out, const Fixed &num) {
	out << num.toFloat();
	return out;
}

/* -------------------------------- Increment ------------------------------- */

Fixed& Fixed::operator++(void) {
	this->fixedPoint += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp_obj = *this;
	this->fixedPoint += 1;
	return temp_obj;
}

/* -------------------------------- Decrement ------------------------------- */

Fixed& Fixed::operator--(void) {
	this->fixedPoint -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp_obj = *this;
	this->fixedPoint -= 1;
	return temp_obj;
}

/* ----------------------------------- Max ---------------------------------- */

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2){
	return num1.getRawBits() > num2.getRawBits() ? num1 : num2; 
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2){
	return num1.getRawBits() > num2.getRawBits() ? num1 : num2; 
}

/* ----------------------------------- Min ---------------------------------- */

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2){
	return num1.getRawBits() > num2.getRawBits() ? num2 : num1; 
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2){
	return num1.getRawBits() > num2.getRawBits() ? num2 : num1; 
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
