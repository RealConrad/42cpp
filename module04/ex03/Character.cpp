#include "Character.hpp"

Character::Character(const std::string& name): name(name) {
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL; // initialize all inventory slots
	}
	for (int i = 0; i < this->backpackCapacity; i++) {
		this->backpack[i] = NULL;
	}
}

Character::Character(const Character& other): name(other.name) {
	for (int i = 0; i < 4; i++) {
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	for (int i = 0; i < this->backpackCapacity; i++) {
		this->backpack[i] = NULL;
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
		for (int i = 0; i < this->backpackCapacity; i++) {
			delete this->backpack[i];
			this->backpack[i] = NULL;
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		delete this->inventory[i];
	}
	for (int i = 0; i < this->backpackCapacity; i++) {
		delete this->backpack[i];
	}
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
	delete m;
	std::cout << "Inventory is full, unequip first!" << std::endl;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		for (int i = 0; i < this->backpackCapacity; i++) {
			if (!this->backpack[i]) {
				std::cout << "Unequipping: " << this->inventory[idx]->getType() << std::endl;
				this->backpack[i] = this->inventory[idx];
				this->inventory[idx] = NULL;
				return ;
			}
		}
		std::cout << "Backpack is full, cannot unequip to backpack" << std::endl;
	}
	else
		std::cout << "Invalid inventory index" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && inventory[idx]) {
		this->inventory[idx]->use(target);
		return ;
	}
	std::cout << "Invalid use index" << std::endl;
}
