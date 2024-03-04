#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain *brain;

	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat& copy); // copy constructor
		Cat& operator=(const Cat& copy); // copy assignment constructor
		void makeSound() const;
};

#endif