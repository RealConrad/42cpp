#include "WrongCat.hpp"

WrongCat::WrongCat() {
	WrongAnimal::type = "Wrong Cat";
	std::cout << "Wrong cat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat desconstructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
