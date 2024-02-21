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

		// Comparison
		/*
			Why do we use const reference to `num`?
			1. More efficient (avoids copying new Class/object)
			2. `Const` correctness (Not a modifiable value)
			3. Semantic Clarity (More appropriate for operator overloads, where your not changing the value).
		*/
		bool operator>(const Fixed &num) const;
		bool operator<(const Fixed &num) const;
		bool operator<=(const Fixed &num) const;
		bool operator>=(const Fixed &num) const;
		bool operator!=(const Fixed &num) const;
		bool operator==(const Fixed &num) const;

		// Arthimetic
		Fixed operator+(const Fixed &num) const;
		Fixed operator-(const Fixed &num) const;
		Fixed operator*(const Fixed &num) const;
		Fixed operator/(const Fixed &num) const;

		// Increment/decrement
		Fixed& operator++(void); // before
		/*
			The int parameter is a dummy parameter.
			Its value is not used within the function;
			its presence in the function signature is solely to distinguish the postfix
			operator from the prefix operator.
			Compiler just knows which one to call.
		*/
		Fixed operator++(int); // after
		Fixed& operator--(void); // before
		Fixed operator--(int); // after

		// Max/min
		/*
			Static functions are not "tied" to an onject/class. You can call these functions
			without declaring the class. It can only access static member functions/properties (dont have access to the class pointer).
		*/
		static const Fixed& max(const Fixed& num1, const Fixed& num2);
		static Fixed& max(Fixed& num1, Fixed& num2);
		static const Fixed& min(const Fixed& num1, const Fixed& num2);
		static Fixed& min(Fixed& num1, Fixed& num2);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &num);

#endif