#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm> 

class Span {
	private:
		std::vector<int> values;
		size_t maxCapacity;
	public:
		Span();
		Span(int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int num);
		void addMultiple(int amount);
		void display();
		int shortestSpan();
		int longestSpan();

		class StorageFullException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Cannot store more numbers";
				}
		};
		class InvalidSpanException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Span cannot be found, try adding more numbers";
				}
		};
		class NothingToDisplayException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Nothing to display, try adding some numbers first";
				}
		};
};

#endif