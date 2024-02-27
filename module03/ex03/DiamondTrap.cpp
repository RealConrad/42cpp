#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->name = name;
	FragTrap::hitPoints = 100;
	ScavTrap::energyPoints = 50;
	FragTrap::attackDamage = 30;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap deconstructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "My name: " << this->name << std::endl;
	std::cout << "ScavTrap: " << ScavTrap::name << std::endl;
	std::cout << "FragTrap: " << FragTrap::name << std::endl;
	std::cout << "ClapTrap: " << ClapTrap::name << std::endl;
}
