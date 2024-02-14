#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"


class HumanB {
	private:
		std::string name;
		Weapon *weapon; // Make it pointer as HumanB doesn't always have a weapon
	public:
		HumanB(std::string name);
		void attack(void);
		void setName(const std::string& name);
		void setWeapon(Weapon& weapon);
};

#endif