#include "Zombie.hpp"

Zombie::~Zombie(void) {
	std::cout << this->name << " is destroyed" << std::endl;
}

void Zombie::annouce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}
