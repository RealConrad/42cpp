#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"


class HumanB {
	private:
		Weapon *weapon; // Make it pointer as HumanB doesn't always have a weapon
		std::string name;
	public:
		HumanB();
		void attack(void);
		void setName(const std::string& name);
		void setWeapon(Weapon& weapon);
};

#endif