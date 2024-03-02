#include "Animal.hpp"

Animal::Animal() {
	this->type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) {
	this->type = type;
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal deconstructor called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal noises" << std::endl;
}

Animal::Animal(const Animal& copy) {
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = copy.type;
}

Animal& Animal::operator=(const Animal& copy) {
	this->type = copy.type;
	std::cout << "Animal copy assignment operator called" << std::endl;
	return *this;
}

std::string Animal::getType() const {
	return this->type;
}
