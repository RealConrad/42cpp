#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	/*
	Reason for small increase:
		- When you increment the internal fixedPoint value by 1, 
			it represents a very small increment in the actual floating-point value because of the scaling factor.
			This is correct for fixed-point arithmetic with a high precision (many fractional bits).
		- The scaling factor determined by fractionalBits, when converting back to a float for output. 
			the increment appears as a very small change. 
		- (e.g.,  fractionalBits = 8, then 1 in fixed-point representation is 1 / 2^8 = 0.00390625 in float)
	*/
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	
	
	Fixed c(Fixed(6.0f) / Fixed(0));
	std::cout << c << std::endl;
	return 0;
}
