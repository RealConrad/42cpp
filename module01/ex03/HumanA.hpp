#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"


class HumanA {
	private:
		Weapon weapon;
		std::string name;
	public:
		HumanA();
		void setName(const std::string& name);
		void attack(void);
		void setWeapon(const Weapon& weapon);	
};

#endif