#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap deconstructor called" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now guarding the gate" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->energyPoints <= 0 || this->hitPoints <= 0) {
		std::cout << "ScavTrap " << this->name << " has no energy/hit points left" << std::endl;
	} else {
		this->energyPoints -= 1;
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage" << std::endl;
	}
}
