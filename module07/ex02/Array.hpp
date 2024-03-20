#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <exception>

template <class T>
class Array {
	private:
		T* arr;
		int size;
	public:
		Array();
		Array(int amount);
		Array(const Array<T>& other);
		Array& operator=(const Array<T>& other);
		T& operator[](int idx);
		~Array();
		int getSize();

		class IndexOutOfRange: public std::exception {
			virtual const char* what() const throw() {
				return "Index out of bounds";
			}
		};
};

#include "Array.tpp"

#endif