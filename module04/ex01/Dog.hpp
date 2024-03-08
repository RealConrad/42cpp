#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	private:
		Brain *brain;

	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog& copy); // copy constructor
		Dog& operator=(const Dog& copy); // copy assignment constructor
		void makeSound() const;
		void addIdea(const std::string& idea);
		void printIdeas() const;
};

#endif