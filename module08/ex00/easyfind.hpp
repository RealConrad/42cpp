#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>

class NotFoundException: public std::exception {
	virtual const char* what() const throw() {
		return "Not found in container :(";
	}
};

template <typename T>
int easyfind(T container, int value) {
	typename T::iterator iter;
	for (iter = container.begin(); iter != container.end(); iter++) {
		if (*iter == value)
			return *iter;
	}
	throw NotFoundException();
}

#endif