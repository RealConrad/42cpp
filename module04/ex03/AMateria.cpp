#include "AMateria.hpp"

AMateria::AMateria(void) {
	this->type = "VOID";
	// std::cout << "AMATERIA default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) {
	this->type = type;
	// std::cout << "AMATERIA parameterized constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
	this->type = other.type;
	// std::cout << "AMATERIA copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		this->type = other.type;
	}
	// std::cout << "AMATERIA assignment operator called" << std::endl;
	return *this;
}

AMateria::~AMateria() {
	// std::cout << "AMATERIA deconstructor called" << std::endl;
}

std::string const& AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMATERIA: Shooting at " << &target << std::endl;
}
