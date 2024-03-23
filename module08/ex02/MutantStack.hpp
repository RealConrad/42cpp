#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <list>

/*
std::stack explanations:
	- std::stack is designed to only allow access to the top element Last-In-First-Out (LIFO principle) where elements are inserted/extracted from 1 end of the container.
	- std::stack itself is a "container adapator", not a container, it holds another container inside it and provides
		a limited interface to that container for some operations (e.g. pop, push)
	- We use std::deque by default because its the most efficint, but can change it to list/vector
*/
template < typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> { // inherit from std::stack so we have its functionalities
	public:
		MutantStack(): std::stack<T, Container>() {}
		MutantStack(const MutantStack& other): std::stack<T, Container>(other) {
			std::cout << "Copy constructor called" << std::endl;
		}
		MutantStack operator=(const MutantStack& other) {
			std::cout << "Copy assignmment called" << std::endl;
			if (this != &other) {
				std::stack<T, Container>::operator=(other);
			}
			return *this;
		}
		~MutantStack() {}

		// Inherit member Expose iterators of std::stack
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}
		const_iterator end() const {
			return this->c.end();
		}
		const_iterator begin() const {
			return this->c.begin();
		}
};

#endif