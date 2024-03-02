#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
	this->type = type;
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal deconstructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal noises" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	this->type = copy.type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
	this->type = copy.type;
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	return *this;
}

std::string WrongAnimal::getType() const {
	return this->type;
}
