#include "Cat.hpp"

Cat::Cat() {
	Animal::type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat desconstructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

Cat::Cat(const Cat& copy): Animal(copy) {
	this->brain = new Brain();
	*this = copy;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& copy) {
	this->type = copy.type;
	*this->brain = *copy.brain;
	std::cout << "Cat copy assignment called" << std::endl;
	return *this;
}
