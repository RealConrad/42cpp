#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
	protected:
		std::string type;
	
	public:
		AAnimal();
		AAnimal(std::string type);
		virtual ~AAnimal();
		AAnimal(const AAnimal& copy); // copy constructor
		AAnimal& operator=(const AAnimal& copy); // copy assignment operator

		virtual void makeSound() const = 0; // now a pure virtual method
		std::string getType() const;
};

#endif