#include "Ice.hpp"

Ice::Ice(): AMateria::AMateria("ice") {

}

Ice::~Ice() {
	
}

AMateria* Ice::clone() const {
	return new Ice(*this); // returns a new instance
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
