#include "HumanA.hpp"

HumanA::HumanA() {
	this->weapon.setType("Katana");
}

void HumanA::attack(void) {
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}

void HumanA::setWeapon(const Weapon& weapon) {
	this->weapon = weapon;
}

void HumanA::setName(const std::string& name) {
	this->name = name;
}
