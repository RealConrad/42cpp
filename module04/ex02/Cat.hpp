#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal {
	private:
		Brain *brain;

	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat& copy); // copy constructor
		Cat& operator=(const Cat& copy); // copy assignment constructor
		void makeSound() const;
		void addIdea(const std::string& idea);
		void printIdeas() const;
};

#endif