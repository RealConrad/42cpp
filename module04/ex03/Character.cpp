#include "Character.hpp"

Character::Character(const std::string& name): name(name) {
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL; // initialize all inventory slots
	}
}

Character::Character(const Character& other): name(other.name) {
	for (int i = 0; i < 4; i++) {
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		this->name = other.name;
		for (int i = 0; i < 4; i++) {
			delete this->inventory[i];
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return *this;
}


Character::~Character() {

}

std::string const& Character::getName() const {
	return this->name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!this->inventory[i]) { // find first avaliable inventory space
			this->inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory is full, unequip first!" << std::endl;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		this->inventory[idx] = NULL; // CHANGE ???
		return ;
	}
	std::cout << "Invalid inventory index" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && inventory[idx]) {
		this->inventory[idx]->use(target);
		return ;
	}
	std::cout << "Invalid index" << std::endl;
}
