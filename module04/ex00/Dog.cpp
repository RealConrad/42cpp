#include "Dog.hpp"

Dog::Dog() {
	Animal::type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog desconstructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Bark" << std::endl;
}
