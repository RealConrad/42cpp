#include "AAnimal.hpp"

AAnimal::AAnimal() {
	this->type = "AAnimal";
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) {
	this->type = type;
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal deconstructor called" << std::endl;
}

// void AAnimal::makeSound() const {
// 	std::cout << "AAnimal noises" << std::endl;
// }

AAnimal::AAnimal(const AAnimal& copy) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->type = copy.type;
}

AAnimal& AAnimal::operator=(const AAnimal& copy) {
	this->type = copy.type;
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	return *this;
}

std::string AAnimal::getType() const {
	return this->type;
}
