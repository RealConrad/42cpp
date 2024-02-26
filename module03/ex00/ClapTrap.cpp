#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 10;
	std::cout << "Created " << this->name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Deconstructor called for " << this->name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints <= 0 || this->hitPoints <= 0) {
		std::cout << this->name << " has no energy/hit points left" << std::endl;
	} else {
		this->energyPoints -= 1;
		std::cout << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->energyPoints <= 0 || this->hitPoints <= 0) {
		std::cout << this->name << " has no energy/hit points left" << std::endl;
	} else if (static_cast<unsigned int>(this->hitPoints) <= amount) {
		std::cout << this->name << " is dead" << std::endl;
		this->hitPoints -= amount;
		this->energyPoints -= 1;
	} else {
		this->hitPoints -= amount;
		this->energyPoints -= 1;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints <= 0 || this->hitPoints <= 0) {
		std::cout << this->name << " has no energy/hit points left" << std::endl;
	} else {
		this->hitPoints += amount;
		this->energyPoints -= 1;
		std::cout << this->name << " repairs itself for " << amount << std::endl;
	}
}
