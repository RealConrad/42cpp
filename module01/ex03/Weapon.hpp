#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	private:
		std::string type;

	public:
		Weapon(std::string type);
		std::string getType(void);
		void setType(const std::string& type);
};

#endif