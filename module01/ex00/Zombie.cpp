
#include "Zombie.hpp"

/**
 * @brief Construct a new Zombie with a given name
 * @param name The name of the zombie 
 */
Zombie::Zombie(std::string name) {
	this->name = name;
}

void Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/**
 * @brief Gets called when the object is destroyed. Prints a message indicating
 * it got destroyed.
 */
Zombie::~Zombie() {
	std::cout << this->name << " is destroyed" << std::endl;
}
