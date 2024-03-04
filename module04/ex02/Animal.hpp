#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string type;
	
	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal& copy); // copy constructor
		Animal& operator=(const Animal& copy); // copy assignment operator

		virtual void makeSound() const = 0; // make it so that no one can instansiate it
		std::string getType() const;
};

#endif