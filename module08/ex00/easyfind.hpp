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
	typename T::iterator iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw NotFoundException();
	else
		return *iter;
}

#endif