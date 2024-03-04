#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		~WrongAnimal();
		WrongAnimal(const WrongAnimal& copy); // copy constructor
		WrongAnimal& operator=(const WrongAnimal& copy); // copy assignment operator

		void makeSound() const;
		std::string getType() const;
};

#endif