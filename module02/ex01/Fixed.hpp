#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int fixedPoint;
		static const int fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &copy);
		Fixed& operator=(const Fixed &num);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &num);

#endif