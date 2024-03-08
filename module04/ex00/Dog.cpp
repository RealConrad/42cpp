#include "Dog.hpp"

Dog::Dog() {
	Animal::type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		std::cout << "Dog copy assignment called" << std::endl;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog desconstructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Bark" << std::endl;
}
