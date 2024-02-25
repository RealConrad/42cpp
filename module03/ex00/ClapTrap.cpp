#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 10;
	std::cout << "Created " << this->name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	std::cout << this->name << " is attacking " << target << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	// take damage
}

void ClapTrap::beRepaired(unsigned int amount) {
	// heal
}
