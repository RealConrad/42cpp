#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap constructor was called" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap desconstructor called" << std::endl;
}

void FragTrap::highFiveGuys(void) {
	if (this->energyPoints <= 0) {
		std::cout << "FragTrap out of energy!" << std::endl;
	} else {
		std::cout << "FragTrap is requesting a high five" << std::endl;
		this->energyPoints -= 1;
	}
}
