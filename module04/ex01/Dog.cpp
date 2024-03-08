#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() {
	Animal::type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog desconstructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Bark" << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy) {
	this->brain = new Brain();
	*this = copy;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	this->type = copy.type;
	*this->brain = *copy.brain;
	std::cout << "Dog copy assignment called" << std::endl;
	return *this;
}

void Dog::addIdea(const std::string& idea) {
	this->brain->addIdea(idea);
}

void Dog::printIdeas() const {
	this->brain->printIdeas();
}

